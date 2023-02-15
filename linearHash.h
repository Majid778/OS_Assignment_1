#pragma once
#include <bits/stdc++.h>
#include <iostream>

#include "linkedList.h"
#include "postallinkedlist.h"
#include <string.h>
using namespace std;

class Pair{
	public:
		int primarysize;
		int primarycapacity;
		LinkedList *primary;
		LinkedList *overflow;
		Pair(){
			primarysize = 0;
			primary = NULL;
			overflow = NULL;
		}
		Pair(LinkedList *primary, LinkedList *overflow, int primarycapacity){
			this->primarysize = 0;
			this->primarycapacity = primarycapacity;
			this->primary = primary;
			this->overflow = overflow;
		}
        LinkedList *getPrimary(){
            return this->primary;
        }
        LinkedList *getOverflow(){
            return this->overflow;
        }
		int getPrimarySize(){
			return this->primarysize;
		}
		void incrementPrimarySize(){
			this->primarysize++;
		}
};

class LinearHash {	
	private:
	    Pair *pairs;        
        int size;                    
        int capacity;               
        int global_depth;							
public:
	 LinearHash(int capacity, int primarycapacity){
            this->capacity = capacity;
            this->pairs = new Pair[capacity];
            for (int i = 0; i < capacity; i++) {
                pairs[i] = Pair(new LinkedList(), new LinkedList(), primarycapacity);
            }
            this->global_depth = 0;
            this->size = 0;
        } 
	~LinearHash(){
            for (int i = 0; i < capacity; i++) {
                delete pairs[i].getPrimary();
                delete pairs[i].getOverflow();
            }
            delete[] pairs;
        } 
	 int hash(int key, int depth) {
            return key % (int) pow(2, depth);
        }
	unsigned long hashCode(string key){
		unsigned long hash = 5381;
		for(int i = 0; i < key.length(); i++){
			hash = ((hash << 5) + hash) + key[i];
		}
		return hash;
	}
	 void split(int bucket_no) {
            Pair& p = pairs[bucket_no];
            LinkedList* old_primary = p.getPrimary();
            LinkedList* old_overflow = p.getOverflow();
            LinkedList* new_primary = new LinkedList(old_primary->getCapacity());
            LinkedList* new_overflow = new LinkedList(old_overflow->getCapacity());
            p = Pair(new_primary, new_overflow);
            
            for (Node* node = old_primary->front(); node != NULL; node = node->next) {
                Voter v = node->voter;
                int hashed_key = hash(hashCode(v.key), global_depth+1);
                if (hashed_key == bucket_no) {
                    new_primary->push_front(v);
                } else {
                    new_overflow->push_front(v);
                }
            }
            for (Node* node = old_overflow->front(); node != NULL; node = node->next) {
                Voter v = node->voter;
                int hashed_key = hash(hashCode(v.key), global_depth+1);
                if (hashed_key == bucket_no) {
                    new_primary->push_front(v);
                } else {
                    new_overflow->push_front(v);
                }
            }
            delete old_primary;
            delete old_overflow;
        }
        
        void insert(Voter v) {
            int hashed_key = hash(hashCode(v.key), global_depth);
            Pair& p = pairs[hashed_key];
            LinkedList* primary = p.getPrimary();
            LinkedList* overflow = p.getOverflow();
            
            if (primary->size() < primary->getCapacity()) {
                primary->push_front(v);
            } else if (overflow->size() < overflow->getCapacity()) {
                overflow->push_front(v);
            } else {
                overflow->push_front(v);
                split(hashed_key);
                if (hashed_key >= pow(2, global_depth)) {
                    global_depth++;
                }
            }
            size++;
        }
	bool remove(const string key, postalLinkedList& postalLinkedList){
		int index = hashCode(key) % capacity;
		if(buckets[index].empty()){
			return false;
		}
		else{
			Node* current = buckets[index].front();
			while(current != NULL){
				if(current->voter.key == key){
					if(current->voter.voted == true){
						postalLinkedList.rm_Node(key);
					}
					buckets[index].rm_Node(key);
					size--;
					return true;
				}
				current = current->next;
			}
			return false;
		}
	}
	Voter* search(const string key){
		int index = hashCode(key) % capacity;
		if(buckets[index].empty()){
			return NULL;
		}
		else{
			Node* current = buckets[index].front();
			while(current != NULL){
				if(current->voter.key == key){
					return &current->voter;
				}
				current = current->next;
			}
			return NULL;
		}
	}
	bool changeVote(const string key, postalLinkedList& postalLinkedList){
		int index = hashCode(key) % capacity;
		if(buckets[index].empty()){
			return false;
		}
		else{
			Node* current = buckets[index].front();
			while(current != NULL){
				if(current->voter.key == key){
					if(current->voter.voted == true){
						postalLinkedList.rm_Node(key);
						current->voter.set_voted(false);
						return true;
					}
					else{
						postalLinkedList.push_front(key, current->voter);
						current->voter.set_voted(true);
						return true;
					}
				}
				current = current->next;
			}
			return false;
		}
	}
	void print(){
		for(int i = 0; i < capacity; i++){
			cout << "Bucket " << i << ": ";
			buckets[i].print();
		}
	}
};

		



