#ifndef PriorityQueue_h
#define PriorityQueue_h
class OrderedItem;
class Node;
class ListItem;

class PriorityQueue{
private:
   
    Node *front;
    Node *back;
    int size;
public:
    PriorityQueue();//constructor
    int getSize();//size of the priority queue
    bool isEmpty();//cheching is empty
    void insert(OrderedItem *item);//insert a event
   
    OrderedItem *dequeue();//removing a event
    OrderedItem* getFront();//getting front event
    ~PriorityQueue();
};

#endif /* PriorityQueue_h */
