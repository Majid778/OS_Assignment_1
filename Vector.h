#include "linkedlist.h"
#include <stdexcept>

class Pair
{
public:
    int primarysize;
    int primarycapacity;
    LinkedList *primary;
    LinkedList *overflow;
    Pair();
    Pair(LinkedList *primary, LinkedList *overflow, int primarycapacity);
    LinkedList *getPrimary();
    LinkedList *getOverflow();
    void insert(Voter voter);
    int getPrimarySize();
    void incrementPrimarySize();
    void print();
};

class Vector
{
public:
    Vector();
    Vector(int initial_capacity);
    ~Vector();
    void push_back(const Pair &p);
    int getSize() const;
    Pair &operator[](int index);
    void clear();
    void resize();

private:
    int capacity;
    int size;
    Pair *data;
};