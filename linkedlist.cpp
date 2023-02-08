#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList() {
    head = NULL;

}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insert(int key, int value) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

int LinkedList::get(int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void LinkedList::remove(int key) {
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void LinkedList::print() {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->key << " " << current->value << std::endl;
        current = current->next;
    }
}

//
