#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList {
private:
    Node* get(int index);

public:
    Node *head;

    LinkedList();
    LinkedList(int arr[],int size);
    ~LinkedList();
    int getItem(int position);
    int getLength() ;
    void printItems() ;
    void addEnd(int value) ;
    void addFront(int value) ;
    void addAtPosition(int position, int value);
    void deletePosition(int position) ;
    void deleteFront() ;
    void deleteEnd();
    void removeNode(int value) ;
    void replaceAt(int index, Node *item);
    int search(int value);
};

 


