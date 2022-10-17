#ifndef _NODE_H
#define _NODE_H

class Node {
public:
    int val;
    Node* next;
    Node();
    Node(int val);
    ~Node();
    int getVal() const;
    void setVal(int val);
    Node* getNext() const;
    void setNext(Node* next);

};

#endif 
