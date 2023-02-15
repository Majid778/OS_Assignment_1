
#include <iostream>
#include <fstream>
#include <sstream>
#include "linkedlist.h"
#include <string.h>
#include "linearHash.h"

using namespace std;
void loadFile(LinearHash& LH, string filename){
    //load the file and insert the voters into the hash table
    ifstream file;
    file.open(filename);
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string key;
        string firstname;
        string lastname;
        string zipcode;
        getline(ss, key, ' ');
        getline(ss, firstname, ' ');
        getline(ss, lastname, ' ');
        getline(ss, zipcode);

        cout << key << " " << firstname << " " << lastname << " " << zipcode << endl;
        //create a voter
        Voter v(key, firstname, lastname, zipcode, false);
        LH.insert(v);
    }
    LH.print();
}

void menu(){
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

int main(){

    LinearHash linearHash(50); //create a linear hash table
    string filename = "voters50.csv";
    loadFile(linearHash, filename);
    postalLinkedList postalLinkedList;   //create a postal linked list

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
		cout<<">";
		getline(cin,user_input);
		stringstream sstr(user_input);
		getline(sstr,command,' ');
		getline(sstr,parameter1,' ');
        getline(sstr,parameter2,' ');
        getline(sstr,parameter3,' ');
		getline(sstr,parameter4);
		try
		{		
			if( command =="help" or command=="Help") menu(); 
            else if( command =="l")	; 
			else if( command =="i")	; 
			else if( command=="r")	; 
			else if( command =="bv") ; 
			else if( command =="v")	; 
			else if( command == "perc")  ;
			else if( command =="z")	; 
			else if( command =="o") ;	
			else if( command == "Exit" or command=="exit") ;
		}
		catch(exception &e)
		{
			cout<<"Exception: "<<e.what()<<endl;
		}

	}while(command!="exit" and command!="quit");


    return 0;
}