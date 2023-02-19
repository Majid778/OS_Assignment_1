#include "linkedlist.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

// Voter class

Voter::Voter()
{
}

Voter::Voter(string key, string zipcode, string first_name, string last_name, bool voted)
{
    this->key = key;
    this->zipcode = zipcode;
    this->first_name = first_name;
    this->last_name = last_name;
    this->voted = voted;
}

void Voter::print()
{

    if (voted == 1)
    {
        cout << "PIN: " << key << " Postalcode: " << zipcode << " Firstname: " << first_name << " Last name: " << last_name << " Voted: "
             << "Y" << endl;
    }
    else
    {
        cout << "PIN: " << key << " Postalcode: " << zipcode << " Firstname: " << first_name << " Last name: " << last_name << " Voted:  "
             << "N" << endl;
    }
}

// Node class

Node::Node()
{
    next = nullptr;
}

Node::Node(Voter voter)
{
    this->voter = voter;
    next = nullptr;
}

// LinkedList class

LinkedList::LinkedList()
{
    head = nullptr;
    LLsize = 0;
}

bool LinkedList::empty() const
{
    return head == nullptr;
}

LinkedList::~LinkedList()
{
    while (!empty())
    {
        rm_front();
    }
}

int LinkedList::size() const
{
    return LLsize;
}

void LinkedList::incrementsize()
{
    LLsize++;
}

Node *LinkedList::front()
{
    return head;
}

Voter *LinkedList::get_Node(string PIN) const
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->voter.key == PIN)
        {
            return &temp->voter;
        }
        temp = temp->next;
    }
    return NULL;
}

void LinkedList::push_front(const Voter &e)
{
    if (empty())
    {
        Node *temp = new Node;
        temp->voter = e;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        Node *temp = new Node;
        temp->voter = e;
        temp->next = head;
        head = temp;
    }
    incrementsize();
}

void LinkedList::rm_front()
{
    Node *temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        temp->voter.print();
        temp = temp->next;
    }
}
void LinkedList::print(string PIN)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->voter.key == PIN)
        {
            temp->voter.print();
        }
        temp = temp->next;
    }
}
bool LinkedList::change_Vote(string key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->voter.key == key)
        {
            temp->voter.voted = true;
            return true;
        }
        temp = temp->next;
    }
    return false;
}
