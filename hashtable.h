//define a hashtable
#include "linkedlist.h"
#include "hashtable.cpp"
#include "string.h"
#include <iostream>

using namespace std;

class HashTable
{
public:
    HashTable();
    ~HashTable();
    void insert(int key, int value);
    int get(int key);
    void remove(int key);
    void print();
private:
    struct Data {
        String first_name;
        String last_name;
        int zipcode;
        char voting_status;
    };
    int hash(int key);
    int size;
    LinkedList* table;
};