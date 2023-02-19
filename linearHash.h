#include <bits/stdc++.h>
#include <iostream>
#include "postallinkedlist.h"

using namespace std;

class LinearHash
{
private:
    Vector pairs;
    int size;
    int vectorcapacity;
    int initialbuckets;
    int currbuckets;
    int primarycapacity;
    int round;
    int splitptr;

public:
    LinearHash(int vectorcapacity, int primarycapacity);
    ~LinearHash();
    int hash(int key, int depth);
    void split(int bucket_no, int hashed_key);
    void addbucket();
    void insert(std::string key, std::string zipcode, std::string first_name, std::string last_name, std::string command, postalLinkedList &postalLinkedList);
    bool remove(const std::string key, postalLinkedList &postalLinkedList);
    Voter *search(const std::string key);
    bool changeVote(const string key, postalLinkedList &postalLinkedList);
    int getsize();
    void print();
    void print(string key);
};