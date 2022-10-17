#include "Node.h"

Node::Node(int val) :val(val) {

    next = nullptr;
}
int Node::getVal() {

    return val;
}
void Node::setVal(int val) {

    this->val = val;
}