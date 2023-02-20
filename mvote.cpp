#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "linearHash.h"

using namespace std;



// Function load the file and insert the voters into the hash table
void loadFile(LinearHash &LH, postalLinkedList &pll, string filename, string command)
{
    ifstream file;
    file.open(filename);
    string line;
    // check if file is open
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return;
    } // read the file line by line
    while (getline(file, line))
    {
        stringstream ss(line);
        string key;
        string firstname;
        string lastname;
        string zipcode;
        getline(ss, key, ' ');
        getline(ss, firstname, ' ');
        getline(ss, lastname, ' ');
        getline(ss, zipcode);
        LH.insert(key, zipcode, firstname, lastname, command, pll); // insert the voter into the hash table
    }
    //LH.print();
    cout << "File loaded successfully..." << endl;
}
// Function to print the menu
void menu()
{
    cout << "Commands:" << endl;
    cout << "l <pin>" << endl;
    cout << "i <pin> <lname> <fname> <zip>" << endl;
    cout << "r <pin>" << endl;
    cout << "bv <fileofkeys>" << endl;
    cout << "v" << endl;
    cout << "perc" << endl;
    cout << "z <zipcode>" << endl;
    cout << "o" << endl;
    cout << "exit" << endl;
}

int main(int argc, char *argv[])
{
    int INITIALCAPACITY = 2;// initial buckets of the hash table
    string filename;
    int PRIMARYBUCKETCAPACITY;
    // check if the user has entered the correct number of arguments
    if (argc < 4)
    {
        filename = argv[2];
    }
    else
    {
        if (strcmp(argv[1], "-f") == 0)
        {
            filename = argv[2];
            stringstream s(argv[4]);
            s >> PRIMARYBUCKETCAPACITY;
        }
        else
        {
            filename = argv[4];
            stringstream s(argv[2]);
            s >> PRIMARYBUCKETCAPACITY;
        }
    }

    // filename = "voters100000.csv";
    LinearHash LH(INITIALCAPACITY, PRIMARYBUCKETCAPACITY); // create a linear hash table
    LH.addbucket();
    postalLinkedList postalLinkedList;            // create a postal linked list
    loadFile(LH, postalLinkedList, filename, ""); // load the file into the hash table

    string user_input;
    string command;
    string parameter1;
    string parameter2;
    string parameter3;
    string parameter4;

    menu();
    // loop until the user enters exit
    do
    {
        parameter1 = "";
        parameter2 = "";
        parameter3 = "";
        parameter4 = "";
        cout << ">"; // prompt the user to enter a command
        getline(cin, user_input);
        stringstream sstr(user_input);
        getline(sstr, command, ' ');
        getline(sstr, parameter1, ' ');
        getline(sstr, parameter2, ' ');
        getline(sstr, parameter3, ' ');
        getline(sstr, parameter4);
        try
        {
            if (command == "help" or command == "Help")
                menu();
            else if (command == "l") // look up a voter by pin number and print their information
                LH.print(parameter1);
            else if (command == "i") // insert a voter into the hash table using their pin number, last name, first name, and zip code
                LH.insert(parameter1, parameter2, parameter3, parameter4, command, postalLinkedList);
            else if (command == "r") // change the vote of a voter by their pin number
            {
                LH.changeVote(parameter1, postalLinkedList);
                postalLinkedList.print();
            }
            else if (command == "bv") // load a file of pin numbers and change the vote of each voter
                loadFile(LH, postalLinkedList, parameter1, "bv");
            else if (command == "v") // print the number of voters who have voted
                cout << postalLinkedList.getsize() << " people have voted so far." << endl;
            else if (command == "perc") // print the percentage of voters who have voted
                cout << ((double)postalLinkedList.getsize() / (double)LH.getsize()) * 100 << "% of people have voted so far" << endl;
            else if (command == "z") // print the voters who have voted in a given zip code
                postalLinkedList.print_zipcode(parameter1);
            else if (command == "o") // print the voters who have voted in descending order of number of votes their zip code
                postalLinkedList.sort_descending();
            else if (command == "exit")
                ;
            else
                cout << "Invalid command. Type 'help' for a list of commands." << endl;
        }
        catch (exception &e)
        {
            cout << "Exception: " << e.what() << endl;
        }

    } while (command != "exit" and command != "quit");

    return 0;
}