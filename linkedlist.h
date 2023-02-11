#include "hashtable.h"


class Node {
public:
    int key;
    int zipcode;
    String first_name;
    String last_name;
    bool voted;
    Node(int key, int zipcode, String first_name, String last_name, bool voted) {
        this->key = key;
        this->zipcode = zipcode;
        this->first_name = first_name;
        this->last_name = last_name;
        this->voted = voted;
        this->next = NULL;
    }
    Node *next;
};

//declare a basic linked list, which will be used to make the primary and the overflow buckets.
class LinkedList {
public:
	Node node;

    //this is like a constructor, and defines a single linked list element.
    LinkedList(){
        this->node = Node(0, 0, "", "", 0);
    }
    LinkedList(int key, int zipcode, String first_name, String last_name, bool voted){
        this->node = Node(key, zipcode, first_name, last_name, voted);
    }
    add_node(int key, int zipcode, String first_name, String last_name, bool voted){
        Node *new_node = new Node(key, zipcode, first_name, last_name, voted);
        if (this->next == NULL){
            this->next = new_node;
        }
        else{
            Node *temp = this->next;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new_node;
        }
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
};