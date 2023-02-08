#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <stack>
#include "String.h"




using namespace std;

class HashNode//Class for hashnode
{
	private:
		int key;
        int postalcode;
		int zipcode;
        String first_name;
        String last_name;
        bool voted;
	public:
		HashNode(int key)
		{
			this->key = key;
			this->zipcode = 0;
            this->first_name = "";
            this->last_name = "";
		}
		int getkey()
		{
			return key;
		}
		int getzipcode()
		{
			return zipcode;
		}
        String getfirst_name()
        {
            return first_name;
        } 
        String getlast_name()
        {
            return last_name;
        }
        bool getvoted()
        {
            return voted;
        }

		friend class HashTable;
};

class HashTable
{
	private:
		friend class HashNode;
		int size;
		int capacity;

	public:
		list<HashNode> *buckets;
		HashTable(int capacity);
		unsigned long Selected_hashCode(int key);
		unsigned long hashCode1(int key);
        unsigned long hashCode2(int key);
		void insert(int key);
		HashNode* search(int key);
		void Hashsearch(unsigned long int hashcode);
		void erase(int key);
		int getSize();

		~HashTable();
};

HashTable::HashTable(int capacity)//Constructor
{
	buckets = new list<HashNode>[capacity];
	this->capacity = capacity;
	this->size = 0;
}
HashTable::~HashTable()//Destructor
{
	for(int i=0; i<capacity; i++){buckets[i].clear();}
	delete[] buckets;
}
unsigned long HashTable::Selected_hashCode(int key)//Returns appropriate hashcode type depending on users selection
{

}
unsigned long HashTable::hashCode1(int key)//Cyclic Shift 
{


}
unsigned long HashTable::hashCode2(int key)//Polynomial
{

}

void HashTable::insert(int key)//Used to insert the words into the hash function
{
	
}
int HashTable::getSize()//Fucntion to return the size of the Hashtable
{
	return this->size;
}
