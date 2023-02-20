#pragma once
#include <iostream>
#include "Vector.h"
#include <string.h>

class postalNode
{
public:
    std::string postalcode; // zipcode
    LinkedList *voters;     // linked list of voters
    postalNode *next;       // pointer to the next node
    friend class postalLinkedList;
};

class postalLinkedList
{
private:
    postalNode *head; // pointer to the head of the linked list
    int numofzipcodes;
    int size; // size of the linked list

public:
    postalLinkedList();                               // default constructor
    ~postalLinkedList();                              // destructor
    void push_front(std::string zip, const Voter &e); // insert a voter into the linked list
    void rm_front();                                  // remove the head of the linked list
    const std::string front();                        // get the head of the linked list
    bool add_Voter(std::string zip, const Voter &e);  // add a voter to the linked list
    LinkedList *get_Node(std::string zip) const;      // get a voter from the linked list
    postalNode *get_Node_ptr(std::string zip) const;  // get a voter from the linked list
    void print();                                     // print the linked list
    void print_zipcode(std::string key);              // print a voter in the linked list
    bool empty() const;                               // check if the linked list is empty
    int getsize();                                    // get the size of the linked list
    void sort_descending();                           // sort the linked list in descending order
};

class ZipSize // class to store the zipcode and the size of the linked list
{
public:
    std::string zipcode;
    int size;                                   // size of the zipnode
    ZipSize();                                  // default constructor
    ZipSize(std::string z, int s);              // constructor
    bool operator<(const ZipSize &other) const; // overload the < operator
};