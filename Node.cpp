#include "Node.h"

Node::Node() :item(nullptr), next(nullptr)  {}
Node::Node(ListItem *i, Node *n) :item(i), next(n) {}
Node *Node::getNext() {return next;}
void Node::setNext(Node *n) {next=n;}
ListItem *Node::getItem() {return item;}
void Node::setItem(ListItem* li) { item = li; } 
