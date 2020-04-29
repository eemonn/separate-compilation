#include "OrderedItem.h"
#include "PriorityQueue.h"
#include "Node.h"
#include "ListItem.h"
#include "Event.h"

PriorityQueue::PriorityQueue():front(nullptr),size(0){}//constructor
int PriorityQueue::getSize(){return size;}
bool PriorityQueue::isEmpty(){return size==0;}

void PriorityQueue:: insert(OrderedItem *item){
    size++;
   Node* curr = front;
   Node* prev = nullptr;
   while(curr!=nullptr && (dynamic_cast<OrderedItem*>( curr->getItem()))->compareTo(item)) {
       prev = curr;
       curr=curr->getNext();
   }

   //case: only item / first item
    if(prev == nullptr){
       front = new Node(item,front);
   }else{//case: otherwise
       prev->setNext(new Node(item,prev->getNext()));
   }
}//insertion that uses compareTo method for ordered insertion

 OrderedItem* PriorityQueue::dequeue(){
     size--;
     Node *thenode=front;
    OrderedItem* result = dynamic_cast<OrderedItem*>(front->getItem());
    front=front->getNext();
    delete(thenode); //CLEAN UP MEM HERE
    return result;
}//dequeue

OrderedItem *PriorityQueue::getFront(){
    OrderedItem *theItem=nullptr;
    if(front !=nullptr){
        theItem=(dynamic_cast<OrderedItem*>(front->getItem()));
    }
    return theItem;
}//getfront

PriorityQueue::~PriorityQueue(){}//destructor




