#include "hashtable.h"


class Node {
public:

    Node(HashNode* data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }

    Node* next;
    Node* prev;
    HashNode* data;
};



class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insert(int key, int value);
    int get(int key);
    void remove(int key);
    void print();
    bool isEmpty();
    HashNode* search();
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

void LinkedList::insert(int key, int value) {
    Node* newNode = new Node(key, value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int LinkedList::get(int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void LinkedList::remove(int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->key == key) {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            } else {
                tail = temp->prev;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }
}

void LinkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->key << " " << temp->value << endl;
        temp = temp->next;
    }
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}

HashNode* LinkedList::search() {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

