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
    // delete all the linked lists in the vector
    for (int i = 0; i < vectorcapacity; i++)
    {
        delete pairs[i].primary;
        delete pairs[i].overflow;
    }
}

int LinearHash::hash(int key, int depth)
{
    // hash function
    return key % ((int)pow(2, depth) * initialbuckets);
}

void LinearHash::split(int bucket_no, int hashed_key)
{
    // split a bucket into two buckets
    addbucket();
    Pair &p = pairs[bucket_no];
    // save the old primary and overflow linked lists and create new ones
    LinkedList *old_primary = p.getPrimary();
    LinkedList *old_overflow = p.getOverflow();
    LinkedList *new_primary = new LinkedList();
    LinkedList *new_overflow = new LinkedList();
    // update the pair object with the new primary and overflow linked lists
    p = Pair(new_primary, new_overflow, primarycapacity);
    // insert the voters into the new primary and overflow linked lists
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
    // delete the old primary and overflow linked lists
    delete old_primary;
    delete old_overflow;
}
void LinearHash::addbucket()
{
    // add a bucket to the vector of pair objects by creating a new pair object with new primary and overflow linked lists and adding it to the vector
    LinkedList *new_primary = new LinkedList();
    LinkedList *new_overflow = new LinkedList();
    pairs.push_back(Pair(new_primary, new_overflow, primarycapacity));
}

void LinearHash::insert(string key, string zipcode, string first_name, string last_name, string command, postalLinkedList &postalLinkedList)
{
    // insert a voter into the hash table by creating a voter object and inserting it into the primary linked list of the bucket
    Voter v(key, zipcode, first_name, last_name, 0);
    if (search(key) != NULL)
    {
        // if the voter already exists, check if the command is bv(bulk vote) and if it is, change the vote
        if (command == "bv")
        {

            changeVote(key, postalLinkedList);
            return;
        }
        else
        {
            // if the command is not bv, print an error message
            cout << "Voter " << key << " already exists" << endl;
            return;
        }
    }
    int hashed_key1 = hash(stoi(v.key), round);
    int hashed_key2 = hash(stoi(v.key), round + 1);
    // check if the hashed key is greater than the split pointer
    if (hashed_key1 >= splitptr)
    {
        // insert the voter into the primary linked list of the bucket
        Pair &p = pairs[hashed_key1];
        p.insert(v);
        split(splitptr, hashed_key2);

        // check if the primary linked list of the bucket is full
        if (pairs[hashed_key1].getPrimarySize() >= primarycapacity)
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
        // if the hashed key is less than the split pointer, insert the voter into the primary linked list of the bucket
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
        // if the command is bv, change the vote of the newly inserted voter
        changeVote(key, postalLinkedList);
    }

    size++;
    return;
}

Voter *LinearHash::search(const string key)
{
    // get voter using key from hash table
    // need to check both hashed keys to find the voter
    int bucket_index1 = hash(stoi(key), round + 1);
    int bucket_index2 = hash(stoi(key), round);
    Pair bucket1 = pairs[bucket_index1];
    // check the primary and overflow linked lists of the bucket for the first hashed key
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
    // check the primary and overflow linked lists of the bucket for the second hashed key
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
// change the vote of a voter to 1 if the voter exists and has not voted yet
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
    // add the voter to the postal linked list
    const Voter &v2 = *v;
    postalLinkedList.add_Voter(v->zipcode, v2);
    return true;
}

void LinearHash::print()
{
    // print the primary and overflow linked lists of each bucket
    for (int i = 0; i < pow(2, round + 1) * initialbuckets; i++)
    {
        cout << "Bucket " << i << ": " << endl;
        pairs[i].print();
    }
    return;
}

void LinearHash::print(string key)
{
    // print the voter with the given key
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