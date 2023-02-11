#include <iostream>
#include "linkedlist.h"
using namespace std;





class Vector
{
private:
    int *arr;
    int size;
    int capacity;
public:
    //implement a vector of linked lists
    Vector(Pair* p)
    {
        arr = new int[1];
        size = 0;
        capacity = 1;
        arr[0] = p;
    }
    Vector(int i)
    {
        arr = new int[1];
        size = 0;
        capacity = 1;
        arr[0] = i;
    }

    Vector(LinkedList* d)
    {
        arr = new int[1];
        size = 0;
        capacity = 1;
        arr[0] = d;
    }

    Vector()
    {
        arr = new int[1];
        size = 0;
        capacity = 1;
    }

    void push_back(LinkedList* d)
    {
        if (size == capacity)
        {
            int *temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[size] = d;
        size++;
    }
    
    void push_back(Pair* p)
    {
        if (size == capacity)
        {
            int *temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[size] = p;
        size++;
    }

    void pop_back()
    {
        if (size == 0)
        {
            cout << "Vector is empty" << endl;
            return;
        }
        size--;
    }
    int get(int index)
    {
        if (index >= size)
        {
            cout << "Index out of range" << endl;
            return -1;
        }
        return arr[index];
    }
    int getsize()
    {
        return size;
    }
    int getcapacity()
    {
        return capacity;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

