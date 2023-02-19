#pragma once
#include <iostream>
#include "Vector.h"
#include <string.h>

class postalNode
{
public:
    std::string postalcode;
    LinkedList *voters;
    postalNode *next;
    friend class postalLinkedList;
};

class postalLinkedList
{
private:
    postalNode *head;
    int numofzipcodes;
    int size;

public:
    postalLinkedList();
    ~postalLinkedList();
    void push_front(std::string zip, const Voter &e);
    void rm_front();
    const std::string front();
    bool add_Voter(std::string zip, const Voter &e);
    LinkedList *get_Node(std::string zip) const;
    postalNode *get_Node_ptr(std::string zip) const;
    void print();
    void print_zipcode(std::string key);
    bool empty() const;
    int getsize();
    void sort_descending();
};

class ZipSize
{
public:
    std::string zipcode;
    int size;
    ZipSize();
    ZipSize(std::string z, int s);
    bool operator<(const ZipSize &other) const;
};