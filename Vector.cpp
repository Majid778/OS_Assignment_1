#include "Vector.h"
#include <iostream>

using namespace std;

// default constructor
Pair::Pair()
{

    primarysize = 0; // size of primary linked list
    primary = NULL;  // primary linked list
    overflow = NULL; // overflow linked list
}

Pair::Pair(LinkedList *primary, LinkedList *overflow, int primarycapacity)
{
    this->primarysize = 0;
    this->primarycapacity = primarycapacity;
    this->primary = primary;
    this->overflow = overflow;
}

LinkedList *Pair::getPrimary()
{
    return this->primary;
}

LinkedList *Pair::getOverflow()
{
    return this->overflow;
}

void Pair::insert(Voter voter)
{
    // if primary linked list is not full, insert voter into primary linked list
    if (primarysize < primarycapacity)
    {
        primary->push_front(voter);
        primarysize++;
    }
    else // if primary linked list is full, insert voter into overflow linked list
    {
        overflow->push_front(voter);
    }
}

int Pair::getPrimarySize()
{
    return this->primarysize;
}

void Pair::incrementPrimarySize()
{
    this->primarysize++;
}

void Pair::print()
{ // print the primary and overflow linked lists
    primary->print();
    overflow->print();
}

Vector::Vector() : capacity(0), size(0), data(nullptr) {} // default constructor

Vector::Vector(int initial_capacity) : capacity(initial_capacity), size(0), data(new Pair[initial_capacity]) {} // constructor

Vector::~Vector()
{
    // delete the vector
    delete[] data;
}

void Vector::push_back(const Pair &p)
{
    // if the vector is full, resize the vector
    if (size >= capacity)
    {
        resize();
    }
    // add the pair to the vector
    data[size++] = p;
}

int Vector::getSize() const
{
    return size;
}

Pair &Vector::operator[](int index)
{
    // if the index is out of range, throw an exception
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void Vector::clear()
{
    size = 0;
}

void Vector::resize()
{
    // resize the vector by doubling the capacity and copying the old data into the new vector
    int new_capacity = capacity == 0 ? 1 : 2.1 * capacity;
    Pair *new_data = new Pair[new_capacity];
    for (int i = 0; i < size; i++)
    {
        new_data[i] = data[i];
    }
    // delete the old vector and update the vector
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}