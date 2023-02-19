
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "linearHash.h"

using namespace std;
void loadFile(LinearHash &LH, postalLinkedList &pll, string filename, string command)
{
    // load the file and insert the voters into the hash table
    ifstream file;
    file.open(filename);
    string line;
    // check if file is open
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
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
        LH.insert(key, zipcode, firstname, lastname, command, pll);
    }
    LH.print();
    cout << "File loaded successfully..." << endl;
}

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

int main()
{
    int PRIMARYBUCKETCAPACITY = 10;
    int INITIALCAPACITY = 2;
    string filename = "voters500.csv";
    LinearHash LH(INITIALCAPACITY, PRIMARYBUCKETCAPACITY); // create a linear hash table
    LH.addbucket();
    postalLinkedList postalLinkedList; // create a postal linked list
    loadFile(LH, postalLinkedList, filename, "");

    string user_input;
    string command;
    string parameter1;
    string parameter2;
    string parameter3;
    string parameter4;

    menu();

    do
    {
        parameter1 = "";
        parameter2 = "";
        parameter3 = "";
        parameter4 = "";
        cout << ">";
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
            else if (command == "l")
                LH.print(parameter1);
            else if (command == "i")
                LH.insert(parameter1, parameter2, parameter3, parameter4, command, postalLinkedList);
            else if (command == "r")
            {
                LH.changeVote(parameter1, postalLinkedList);
                postalLinkedList.print();
            }
            else if (command == "bv")
                loadFile(LH, postalLinkedList, parameter1, "bv");
            else if (command == "v")
                cout << postalLinkedList.getsize() << " people have voted so far." << endl;
            else if (command == "perc")
                cout << ((double)postalLinkedList.getsize() / (double)LH.getsize()) * 100 << "% of people have voted so far" << endl;
            else if (command == "z")
                postalLinkedList.print_zipcode(parameter1);
            else if (command == "o")
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