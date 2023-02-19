#include "postallinkedlist.h"
#include <iostream>

using namespace std;

postalLinkedList::postalLinkedList()
{
    head = NULL;
    size = 0;
}

postalLinkedList::~postalLinkedList()
{
    while (!empty())
    {
        rm_front();
    }
}

void postalLinkedList::push_front(string zip, const Voter &e)
{

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
    postalNode *current = head;
    head = head->next;
    delete current;
}

const string postalLinkedList::front()
{
    return head->postalcode;
}

bool postalLinkedList::add_Voter(string zip, const Voter &e)
{
    LinkedList *current = get_Node(zip);
    if (empty())
    {
        push_front(zip, e);
        numofzipcodes++;
        return true;
    }
    else if (current != NULL)
    {
        current->push_front(e);
        return true;
    }
    else
    {
        push_front(zip, e);
        numofzipcodes++;
        return true;
    }
    return false;
}

LinkedList *postalLinkedList::get_Node(string zip) const
{
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
{
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
{
    postalNode *current = head;
    while (current != NULL)
    {
        current->voters->print();
        current = current->next;
    }
}

void postalLinkedList::print_zipcode(string key)
{
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
{
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
{
    int s = 0;
    for (postalNode *current = head; current != NULL; current = current->next)
    {
        s = s + current->voters->size();
    }
    return s;
}

void postalLinkedList::sort_descending()
{
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

    for (int i = 0; i < numofzipcodes; i++)
    {
        cout << "Zipcode: " << zipArray[i].zipcode << "| Number of people that have voted: " << zipArray[i].size << endl;
    }
}

ZipSize::ZipSize() {}

ZipSize::ZipSize(std::string z, int s)
{
    zipcode = z;
    size = s;
}

bool ZipSize::operator<(const ZipSize &other) const
{
    return size > other.size;
}
