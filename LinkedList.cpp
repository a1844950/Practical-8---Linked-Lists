#include "LinkedList.h"

Node*  LinkedList::get(int index) {
    Node* temp = head;
    int i = 0;
    while (temp != nullptr && i++ != index) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        return nullptr;
    }
    else {
        return new Node(temp->getVal());
    }
}

LinkedList::LinkedList() { head = NULL; }

LinkedList::LinkedList(int arr[], int size) {
    head = NULL;
    for (int i = 0; i < size; ++i) {
        addEnd(arr[i]);
    }
}

LinkedList::~LinkedList() {
    for (int i = getLength() - 1; i >= 0; i--) {
        deletePosition(i);
    }
}

int LinkedList::getItem(int position) {
    if (position > getLength() || position < 1) {
         cout <<  numeric_limits < int >::max();
        return  numeric_limits < int >::max();
    }
    Node* temp = get(position - 1);
    if (temp != nullptr) {
         cout << temp->getVal() <<  " ";
        return temp->getVal();
    }
    else {
         cout <<  numeric_limits < int >::max();
        return  numeric_limits < int >::max();
    }
}
int LinkedList::getLength() {
    Node* temp = head;
    int len = 0;
    while (temp != nullptr) {
        temp = temp->next;
        len++;
    }
    return len;
}

void LinkedList::printItems() {
    Node* temp = head;
    int len = 0;
    while (temp != nullptr) {
         cout << temp->getVal() << " ";
        temp = temp->next;
        len++;
    }
    return;
}

/*Adds a note at the end of list*/
void LinkedList::addEnd(int newItem) {
    Node* item = new Node(newItem);
    item->next = nullptr;
    if (head == nullptr) {
        head = item;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = item;
}



void LinkedList::addFront(int newItem) {
    Node* item = new Node(newItem);
    if (head == nullptr) {
        head = item;
        return;
    }
    item->next = head;
    head = item;

}


void LinkedList::addAtPosition(int position, int newItem) {
    position--;//convert to index
    if (position < 0) {
        addFront(newItem);
        return;
    }
    if (position > getLength()) {
        addEnd(newItem);
        return;
    }
    Node* item = new Node(newItem);
    item->next = nullptr;
    if (head == nullptr) {
        head = item;
        return;
    }
    Node* temp = head;
    Node* tempNext = head->next;
    int i = 1;
    while (tempNext != nullptr && i++ != position) {
        temp = temp->next;
        tempNext = tempNext->next;
    }
    if (i - 1 == position) {
        item->next = tempNext;
        temp->next = item;
    }
    if (i - 1 != position && tempNext == nullptr) {
        temp->next = item;
    }

}

void LinkedList::deletePosition(int position) {
    int index = position - 1;
    if (position < 1 || position > getLength()) {
         cout << "outside range";
    }
    if (index == 0) {
        head = head->next;
        return;
    }
    Node* temp = head;
    Node* tempNext = head->next;
    int i = 1;
    while (tempNext != nullptr && i++ != index) {
        temp = temp->next;
        tempNext = tempNext->next;
    }
    if (i - 1 == index) {
        temp->next = tempNext->next;
        tempNext->next = nullptr;
        delete tempNext;
    }
    if (i - 1 != index && tempNext == nullptr) {
        //size is less than index
    }

}

void LinkedList::deleteFront() {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        delete head;
    }
    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
}
void LinkedList::deleteEnd() {
    deletePosition(getLength());
}

void LinkedList::removeNode(int value) {
    Node* temp = head;
    Node* tempNext = head->next;
    if (head->getVal() == value) {
        head = head->next;
        return;
    }
    while (tempNext != nullptr && tempNext->getVal() != value) {
        temp = temp->next;
        tempNext = tempNext->next;
    }
    if (tempNext == nullptr) {
        return;//did not find the node
    }
    else {
        temp->next = tempNext->next;//crossing the node to remove it.
        tempNext->next = nullptr;//optional
        delete tempNext;//freeing memory
    }
}

void LinkedList::replaceAt(int index, Node* item) {
    item->next = nullptr;
    if (head == nullptr) {
        head = item;
        return;
    }
    Node* temp = head;
    Node* tempNext = head->next;
    int i = 1;
    while (tempNext != nullptr && i++ != index) {
        temp = temp->next;
        tempNext = tempNext->next;
    }
    if (i - 1 == index) {
        if (tempNext != nullptr) {
            tempNext->setVal(item->getVal());
        }
        else {
            temp->next = item;
        }
    }
    if (i - 1 != index && tempNext == nullptr) {
        temp->next = item;
    }

}

int LinkedList::search(int item) {
    for (int i = 0; i < getLength(); ++i) {
        Node* pNode = get(i);
        if (pNode->getVal() == item) {
             cout << i + 1 << " " <<  endl;//printing position
         //   return pNode->getVal();
           return i + 1;
        }

    }
     cout << "0 ";
    return 0;
}
