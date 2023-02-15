
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


int main(){

//create a linear hash table
LinearHash linearHash(50);
string filename = "voters50.csv";
loadFile(linearHash, filename);
//create a postal linked list
postalLinkedList postalLinkedList;

//insert 10 voters



return 0;
}