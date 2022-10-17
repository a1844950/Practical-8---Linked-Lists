#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "Node.h"
#include <iostream>
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
    void addEnd(int newItem) ;
    void addFront(int newItem) ;
    void addAtPosition(int position, int newItem);
    void deletePosition(int position) ;
    void deleteFront() ;
    void deleteEnd();
    void removeNode(int value) ;
    void replaceAt(int index, Node *item);
    int search(int item);
};
 

#endif 
