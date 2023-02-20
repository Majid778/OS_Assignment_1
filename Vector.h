#include "linkedlist.h"
#include <stdexcept>

class Pair
{
public:
    int primarysize;                                                      // number of voters in primary list
    int primarycapacity;                                                  // capacity of primary list before overflow
    LinkedList *primary;                                                  // primary list
    LinkedList *overflow;                                                 // overflow list
    Pair();                                                               // default constructor
    Pair(LinkedList *primary, LinkedList *overflow, int primarycapacity); // constructor
    LinkedList *getPrimary();                                             // returns primary list
    LinkedList *getOverflow();                                            // returns overflow list
    void insert(Voter voter);                                             // inserts voter into primary list if not at capacity, otherwise inserts into overflow list
    int getPrimarySize();                                                 // returns number of voters in primary list
    void incrementPrimarySize();                                          // increments number of voters in primary list
    void print();                                                         // prints primary list and overflow list
};

class Vector
{
public:
    Vector();                      // default constructor
    Vector(int initial_capacity);  // constructor
    ~Vector();                     // destructor
    void push_back(const Pair &p); // adds a pair to the end of the vector
    int getSize() const;           // returns the size of the vector
    Pair &operator[](int index);   // returns the pair at the given index
    void clear();                  // clears the vector
    void resize();                 // resizes the vector

private:
    int capacity; // capacity of the vector
    int size;     // size of the vector
    Pair *data;   // array of pairs
};