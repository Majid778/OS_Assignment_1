#include <bits/stdc++.h>
#include <iostream>
#include "linearHash.h"
#include <string.h>

using namespace std;

LinearHash::LinearHash(int vectorcapacity, int primarycapacity)
{
    this->vectorcapacity = vectorcapacity;
    this->initialbuckets = vectorcapacity;
    this->currbuckets = vectorcapacity;
    this->primarycapacity = primarycapacity;
    for (int i = 0; i < vectorcapacity; i++)
    {
        LinkedList *new_primary = new LinkedList();
        LinkedList *new_overflow = new LinkedList();
        pairs.push_back(Pair(new_primary, new_overflow, primarycapacity));
    }
    this->round = 0;
    this->size = 0;
    this->splitptr = 0;
}

LinearHash::~LinearHash()
{
    for (int i = 0; i < vectorcapacity; i++)
    {
        delete pairs[i].primary;
        delete pairs[i].overflow;
    }
}

int LinearHash::hash(int key, int depth)
{
    return key % ((int)pow(2, depth) * initialbuckets);
}

void LinearHash::split(int bucket_no, int hashed_key)
{
    addbucket();
    Pair &p = pairs[bucket_no];

    LinkedList *old_primary = p.getPrimary();
    LinkedList *old_overflow = p.getOverflow();
    LinkedList *new_primary = new LinkedList();
    LinkedList *new_overflow = new LinkedList();

    p = Pair(new_primary, new_overflow, primarycapacity);
    for (Node *node = old_primary->front(); node != NULL; node = node->next)
    {
        Voter v = node->voter;
        int index = hash(stoi(v.key), round + 1);
        if (index == bucket_no)
        {
            p.insert(v);
        }
        else
        {
            pairs[index].insert(v);
        }
    }

    for (Node *node = old_overflow->front(); node != NULL; node = node->next)
    {
        Voter v = node->voter;
        int index = hash(stoi(v.key), round + 1);
        if (index == bucket_no)
        {
            p.insert(v);
        }
        else
        {
            pairs[index].insert(v);
        }
    }
    delete old_primary;
    delete old_overflow;
}
void LinearHash::addbucket()
{
    LinkedList *new_primary = new LinkedList();
    LinkedList *new_overflow = new LinkedList();
    pairs.push_back(Pair(new_primary, new_overflow, primarycapacity));
}

void LinearHash::insert(string key, string zipcode, string first_name, string last_name, string command, postalLinkedList &postalLinkedList)
{
    Voter v(key, zipcode, first_name, last_name, 0);
    if (search(key) != NULL)
    {
        if (command == "bv")
        {
            changeVote(key, postalLinkedList);
            return;
        }
        else
        {
            cout << "Voter " << key << " already exists" << endl;
            return;
        }
    }
    int hashed_key1 = hash(stoi(v.key), round);
    int hashed_key2 = hash(stoi(v.key), round + 1);
    if (hashed_key1 >= splitptr)
    {
        Pair &p = pairs[hashed_key1];
        p.insert(v);
        split(splitptr, hashed_key2);
        if (p.getPrimarySize() >= primarycapacity)
        {
            if (splitptr >= currbuckets - 1)
            {
                currbuckets = currbuckets * 2;
                round++;
                splitptr = 0;
            }
            else
            {
                splitptr++;
            }
        }
    }
    else
    {
        Pair &p = pairs[hashed_key2];
        p.insert(v);
        if (p.getPrimarySize() >= primarycapacity)
        {
            split(splitptr, hashed_key2);
            if (splitptr >= currbuckets - 1)
            {
                currbuckets = currbuckets * 2;
                round++;
                splitptr = 0;
            }
            else
            {
                splitptr++;
            }
        }
    }
    if (command == "bv")
    {
        changeVote(key, postalLinkedList);
    }
    size++;
    return;
}
bool LinearHash::remove(const string key, postalLinkedList &postalLinkedList)
{
}
Voter *LinearHash::search(const string key)
{
    // get voter using key from hash table
    bool found = false;
    int bucket_index1 = hash(stoi(key), round + 1);
    int bucket_index2 = hash(stoi(key), round);
    Pair bucket1 = pairs[bucket_index1];
    for (Node *node = bucket1.getPrimary()->front(); node != NULL; node = node->next)
    {
        if (node->voter.key == key)
        {
            return &node->voter;
        }
    }
    for (Node *node = bucket1.getOverflow()->front(); node != NULL; node = node->next)
    {
        if (node->voter.key == key)
        {
            return &node->voter;
        }
    }
    Pair bucket2 = pairs[bucket_index2];
    for (Node *node = bucket2.getPrimary()->front(); node != NULL; node = node->next)
    {
        if (node->voter.key == key)
        {
            return &node->voter;
        }
    }
    for (Node *node = bucket2.getOverflow()->front(); node != NULL; node = node->next)
    {
        if (node->voter.key == key)
        {
            return &node->voter;
        }
    }
    return NULL;
}
bool LinearHash::changeVote(const string key, postalLinkedList &postalLinkedList)
{
    Voter *v = search(key);
    if (v == NULL)
    {
        cout << "Voter " << key << " does not exist" << endl;
        return false;
    }
    else if (v->voted == 1)
    {
        cout << "Voter " << key << " already voted" << endl;
        return false;
    }
    v->voted = 1;
    const Voter &v2 = *v;
    postalLinkedList.add_Voter(v->zipcode, v2);
}

void LinearHash::print()
{
    for (int i = 0; i < pow(2, round + 1) * initialbuckets; i++)
    {
        cout << "Bucket " << i << ": " << endl;
        pairs[i].print();
    }
    return;
}

void LinearHash::print(string key)
{
    if (search(key) == NULL)
    {
        cout << "Voter " << key << " does not exist" << endl;
        return;
    }
    else
    {
        Voter *v = search(key);
        v->print();
    }
}

int LinearHash::getsize()
{
    return size;
}