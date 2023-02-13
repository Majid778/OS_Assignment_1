#include "hashtable.h"



class Voter{
private:
    String key;
    String zipcode;
    String first_name;
    String last_name;
    bool voted;
    voter(String key, String zipcode, String first_name, String last_name, bool voted){
        this->key = key;
        this->zipcode = zipcode;
        this->first_name = first_name;
        this->last_name = last_name;
        this->voted = voted;
    }
    friend class HashTable;
public:
    String get_key(){
        return key;
    }
    String get_zipcode(){
        return zipcode;
    }
    String get_first_name(){
        return first_name;
    }
    String get_last_name(){
        return last_name;
    }
    bool get_voted(){
        return voted;
    }
    void set_voted(bool voted){
        this->voted = voted;
    }
}


class Node {
public:
    Voter voter;
    Node *next;
    Node(){
        next = NULL;
    }
    friend class LinkedList;
};

//declare a basic linked list, which will be used to make the primary and the overflow buckets.
class LinkedList {
private:
	Node* head;
public:
    friend class Node;
	LinkedList(){
        head = NULL;
    }
	~LinkedList(){
        while(!empty()){
            rm_front();
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
	const voterProfile front() const{
        return head->voter;
    }
	voterProfile* get_Node(String PIN) const{
        Node* temp = head;
        while(temp != NULL){
            if(temp->voter.key == PIN){
                return &temp->voter;
            }
            temp = temp->next;
        }
        return NULL;
    }
	Node* get_Node_ptr(String PIN) const{
        Node* temp = head;
        while(temp != NULL){
            if(temp->voter.key == PIN){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
	void push_front(const voterProfile& e){
        Node* temp = new Node;
        temp->voter = e;
        temp->next = head;
        head = temp;
    }
    void push_back(const voterProfile& e){
        Node* temp = new Node;
        temp->voter = e;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
        }
        else{
            Node* temp2 = head;
            while(temp2->next != NULL){
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }
	void rm_front(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void rm_back(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
	bool rm_Node(String PIN){
        Node* temp = head;
        if(temp->voter.key == PIN){
            rm_front();
            return true;
        }
        while(temp->next != NULL){
            if(temp->next->voter.key == PIN){
                Node* temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
	void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->voter.key << " " << temp->voter.zipcode << " " << temp->voter.first_name << " " << temp->voter.last_name << " " << temp->voter.voted << endl;
            temp = temp->next;
        }
    }
    void print(String PIN){
        Node* temp = head;
        while(temp != NULL){
            if(temp->voter.key == PIN){
                cout << temp->voter.key << " " << temp->voter.zipcode << " " << temp->voter.first_name << " " << temp->voter.last_name << " " << temp->voter.voted << endl;
            }
            temp = temp->next;
        }
    }
	bool change_Vote(String key){
        Node* temp = head;
        while(temp != NULL){
            if(temp->voter.key == key){
                temp->voter.voted = true;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int totalVoted(){
        int total = 0;
        Node* temp = head;
        while(temp != NULL){
            if(temp->voter.voted == true){
                total++;
            }
            temp = temp->next;
        }
        return total;
    }
	
};

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
        getPrimary(){
            return this->primary;
        }
        getOverflow(){
            return this->overflow;
        }
};