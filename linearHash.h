#include <bits/stdc++.h>
#include <iostream>
#include "Vector.h"
#include "linkedList.h"
#include "postallinkedlist.h"
#include "String.h"
using namespace std;



class LinearHash {	
	private:
	LinkedList* buckets;		
	int size;					
	int capacity;				
	int numVoted;				
public:
	LinearHash(int capacity); 
	~LinearHash(); 
	unsigned long hashCode(const string key); 
	void insert(const Voter v); 
	bool remove(const string key, postalLinkedList& postalLinkedList);
	Voter* search(const string key); 
	bool modifyVoteStatus(const string key, postalLinkedList& postalLinkedList); 
	int size(); 
	int numofVoted(); 
	float percentofVoted(); 
}

		



