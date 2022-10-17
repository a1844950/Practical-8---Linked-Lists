#include "Node.h"

Node::~Node()
{

}
Node::Node(int val) :val(val) {

    next = nullptr;
}

Node::Node() {
    this->val = 0;
    next = nullptr;
}

int Node::getVal() const
{
    return val;
}

void Node::setVal(int val)
{
    this->val = val;
}

Node* Node::getNext() const
{
    return next;
}

void Node::setNext(Node* next)
{
    this->next = next;
}

