#pragma once
#include <bits/stdc++.h>
#include <iostream>

#include "linkedList.h"
#include "postallinkedlist.h"
#include <string.h>
using namespace std;

class Pair{
	public:
		LinkedList *primary;
		LinkedList *overflow;
		Pair(){
			primary = NULL;
			overflow = NULL;
		}
		Pair(LinkedList *primary, LinkedList *overflow){
			this->primary = primary;
			this->overflow = overflow;
		}
        LinkedList *getPrimary(){
            return this->primary;
        }
        LinkedList *getOverflow(){
            return this->overflow;
        }
};

class LinearHash {	
	private:
	LinkedList* buckets;		
	int size;					
	int capacity;							
public:
	LinearHash(int capacity){
		this->capacity = capacity;
		buckets = new LinkedList[capacity];
		size = 0;
	} 
	~LinearHash(){
		delete[] buckets;
	} 
	unsigned long hashCode(string key){
		unsigned long hash = 5381;
		for(int i = 0; i < key.length(); i++){
			hash = ((hash << 5) + hash) + key[i];
		}
		return hash;
	}
	void insert(Voter v){
		int index = hashCode(v.key) % capacity;
		buckets[index].push_front(v);
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

		



