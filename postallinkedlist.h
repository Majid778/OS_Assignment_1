#include <iostream>
#include "Vector.h"
#include "linkedList.h"
#include "String.h"


class postalNode {
public:
	String postalcode; 
	LinkedList* voters; 
	postalNode* next; 
	friend class postalLinkedList;
};


class postalLinkedList {
private:
	postalNode* head;
	int size; 

public:
	postalLinkedList(){
        head = NULL;
    }
	~postalLinkedList(){
        while(!empty()){
            rm_front();
        }
    }
    void push_front(String pcode, Node* node){
        postalNode* current = new postalNode;
        current->postalcode = pcode;
        current->voters = new LinkedList;
        current->voters->push_front(node);
        current->next = head;
        head = current;
    }
	void rm_front(){
        postalNode* current = head;
        head = head->next;
        delete current;
    }
	bool rm_Node(String pcode){
        if(head == NULL){
            return false;
        }
        else if(head->postalcode == pcode){
            rm_front();
            return true;
        }
        else{
            postalNode* current = head;
            while(current->next != NULL){
                if(current->next->postalcode == pcode){
                    postalNode* temp2 = current->next;
                    current->next = current->next->next;
                    delete temp2;
                    return true;
                }
                current = current->next;
            }
            return false;
        }
    }
	const String front() const{
        return head->postalcode;
    }
    	bool add_Voter(String pcode,Node* voterNode){
        postalNode* current = head;
        while(current != NULL){
            if(current->postalcode == pcode){
                current->voters->push_front(voterNode);
                return true;
            }
            current = current->next;
        }
        return false;
    }
    bool rm_voter(String pcode, Node* node){
        postalNode* current = head;
        while(current != NULL){
            if(current->postalcode == pcode){
                current->voters->rm_Node(pcode);
                return true;
            }
            current = current->next;
        }
        return false;
    }
	LinkedList* get_Node(String pcode) const{
        postalNode* current = head;
        while(current != NULL){
            if(current->postalcode == pcode){
                return current->voters;
            }
            current = current->next;
        }
        return NULL;
    }
	postalNode* get_Node_ptr(String pcode) const{
        postalNode* current = head;
        while(current != NULL){
            if(current->postalcode == pcode){
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
	
	void print(){
        postalNode* current = head;
        while(current != NULL){
            cout << current->postalcode << endl;
            current = current->next;
        }
    }

	void print_zipcode(String key){
        postalNode* current = head;
        while(current != NULL){
            if(current->postalcode == key){
                current->voters->print();
            }
            current = current->next;
        }
    }
    bool empty() const{
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
    }
    int postaltotalVoted(){
        int total = 0;
        postalNode* current = head;
        while(current != NULL){
            total += current->voters->totalVoted();
            current = current->next;
        }
        return total;
    }

    int PercentageVoted(){
    }


	void descendingOrder(){

    }
};