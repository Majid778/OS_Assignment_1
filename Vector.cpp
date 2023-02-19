#include "Vector.h"

Pair::Pair()
{
    primarysize = 0;
    primary = NULL;
    overflow = NULL;
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
    if (primarysize < primarycapacity)
    {
        primary->push_front(voter);
        primarysize++;
    }
    else
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
{
    primary->print();
    overflow->print();
}

Vector::Vector() : capacity(0), size(0), data(nullptr) {}

Vector::Vector(int initial_capacity) : capacity(initial_capacity), size(0), data(new Pair[initial_capacity]) {}

Vector::~Vector()
{
    delete[] data;
}

void Vector::push_back(const Pair &p)
{
    if (size >= capacity)
    {
        resize();
    }
    data[size++] = p;
}

int Vector::getSize() const
{
    return size;
}

Pair &Vector::operator[](int index)
{
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
    int new_capacity = capacity == 0 ? 1 : 2.1 * capacity;
    Pair *new_data = new Pair[new_capacity];
    for (int i = 0; i < size; i++)
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}