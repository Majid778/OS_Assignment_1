#include <bits/stdc++.h>
#include <iostream>
#include "postallinkedlist.h"

using namespace std;

class LinearHash
{
private:
	Vector pairs;		 // vector of pair objects
	int size;			 // number of elements in the hash table
	int vectorcapacity;	 // capacity of the vector
	int initialbuckets;	 // number of buckets in the vector when program starts
	int currbuckets;	 // number of buckets in the vector currently
	int primarycapacity; // capacity of primary linked list in the pair object
	int round;			 // number of rounds elapsed in linear hashing
	int splitptr;		 // pointer to the bucket to be split

public:
	LinearHash(int vectorcapacity, int primarycapacity);																									   // constructor
	~LinearHash();																																			   // destructor
	int hash(int key, int depth);																															   // hash function
	void split(int bucket_no, int hashed_key);																												   // split function to split a bucket into two buckets when a voter is inserter into a overflow bucket
	void addbucket();																																		   // add a bucket to the vector
	void insert(std::string key, std::string zipcode, std::string first_name, std::string last_name, std::string command, postalLinkedList &postalLinkedList); // insert a voter into the hash table
	Voter *search(const std::string key);																													   // search for a voter in the hash table
	bool changeVote(const string key, postalLinkedList &postalLinkedList);																					   // change the vote status of a voter and insert the voter into the postal linked list
	int getsize();																																			   // get the size of the hash table
	void print();																																			   // print the hash table
	void print(string key);																																	   // print a voter in the hash table
};