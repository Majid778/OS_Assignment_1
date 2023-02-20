#include "postallinkedlist.h"
#include <iostream>

using namespace std;

postalLinkedList::postalLinkedList()
{ // default constructor
    head = NULL;
    size = 0;
}

postalLinkedList::~postalLinkedList() // destructor
{
    while (!empty())
    {
        rm_front();
    }
}

void postalLinkedList::push_front(string zip, const Voter &e)
{
    // insert a voter into the front of the linked list
    postalNode *current = new postalNode;
    current->postalcode = zip;
    current->voters = new LinkedList;
    current->voters->push_front(e);
    current->next = head;
    head = current;
    size++;
}

void postalLinkedList::rm_front()
{
    // remove the head of the linked list
    postalNode *current = head;
    head = head->next;
    delete current;
}

const string postalLinkedList::front()
{
    // get the head of the linked list
    return head->postalcode;
}

bool postalLinkedList::add_Voter(string zip, const Voter &e)
{
    // add a voter to the linked list
    LinkedList *current = get_Node(zip);
    if (empty()) // if the linked list is empty create a new node
    {
        push_front(zip, e);
        numofzipcodes++;
        return true;
    }
    else if (current != NULL) // if the zipcode is already in the linked list add the voter to the linked list
    {
        current->push_front(e);
        return true;
    }
    else // if the zipcode is not in the linked list
    {
        push_front(zip, e); // insert the voter into the linked list
        numofzipcodes++;
        return true;
    }
    return false;
}

LinkedList *postalLinkedList::get_Node(string zip) const // get a voter from the linked list
{                                                        // get a the voters from the linked list using the zipcode
    postalNode *current = head;
    while (current != NULL)
    {
        if (current->postalcode == zip)
        {
            return current->voters;
        }
        current = current->next;
    }
    return NULL;
}

postalNode *postalLinkedList::get_Node_ptr(string zip) const
{ // get a the voters pointer from the linked list using the zipcode
    postalNode *current = head;
    while (current != NULL)
    {
        if (current->postalcode == zip)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void postalLinkedList::print()
{ // print the linked list
    postalNode *current = head;
    while (current != NULL)
    {
        current->voters->print();
        current = current->next;
    }
}

void postalLinkedList::print_zipcode(string key)
{ // print all the voters in the zipcode
    postalNode *current = head;
    while (current != NULL)
    {
        if (current->postalcode == key)
        {
            current->voters->print();
        }
        current = current->next;
    }
}
bool postalLinkedList::empty() const
{ // check if the linked list is empty
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int postalLinkedList::getsize()
{ // get the size of the linked list
    int s = 0;
    for (postalNode *current = head; current != NULL; current = current->next)
    {
        s = s + current->voters->size();
    }
    return s;
}

void postalLinkedList::sort_descending()
{ // insert linked list into an array and sort the array
    ZipSize zipArray[numofzipcodes];
    int index = 0;
    postalNode *current = head;
    while (current != nullptr)
    {
        LinkedList *voters = current->voters;
        zipArray[index] = ZipSize(current->postalcode, voters->size());
        index++;
        current = current->next;
    }
    // sort the array
    for (int i = 0; i < numofzipcodes; i++)
    {
        for (int j = i + 1; j < numofzipcodes; j++)
        {
            if (zipArray[i].size < zipArray[j].size)
            {
                ZipSize temp = zipArray[i];
                zipArray[i] = zipArray[j];
                zipArray[j] = temp;
            }
        }
    }
    // print the array
    for (int i = 0; i < numofzipcodes; i++)
    {
        cout << "Zipcode: " << zipArray[i].zipcode << "| Number of people that have voted: " << zipArray[i].size << endl;
    }
}

ZipSize::ZipSize() {} // default constructor

ZipSize::ZipSize(std::string z, int s) // constructor
{
    zipcode = z;
    size = s;
}

bool ZipSize::operator<(const ZipSize &other) const
{
    return size > other.size;
}
