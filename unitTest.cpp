#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PriorityQueue.h"
#include "Simulation.h"
#include "OrderedItem.h"
#include "partArrival.h"

#include "startAssembly.h"
#include "productArrival.h"
#include "endAssembly.h"

TEST_CASE("Priority Queue insertion test here","[PriorityQueue]"){
   
    PriorityQueue *p=new PriorityQueue();
    Simulation *s=new Simulation();
    OrderedItem *other=new partArrival(10,20,s);
    p->insert(other);
    REQUIRE(p->getSize()==1);
    
    }

TEST_CASE("Priority Queue dequeue test here","[PriorityQueue]"){
    PriorityQueue *p=new PriorityQueue();
    Simulation *s=new Simulation();
    OrderedItem *other=new partArrival(10,20,s);
     OrderedItem *other2=new partArrival(20,20,s);
    p->insert(other);
    p->insert(other2);
    p->dequeue();
    REQUIRE(p->getSize()==1);
}

TEST_CASE("Priority Queue isEmpty test here","[PriorityQueue]"){
     PriorityQueue *p=new PriorityQueue();
      Simulation *s=new Simulation();
   
    
    OrderedItem *other=new partArrival(10,20,s);
    OrderedItem *other2=new partArrival(20,20,s);
    REQUIRE(p->isEmpty()==true);//no item is inserted in the priority queue
}
TEST_CASE("Checking ordered insertion","[PriorityQueue]"){
    PriorityQueue *p=new PriorityQueue();
    Simulation *s=new Simulation();
      
    //creating event object
    OrderedItem *other=new partArrival(10,2,s);
    OrderedItem *other2=new partArrival(20,20,s);
    OrderedItem *other3=new partArrival(20,1,s);
    OrderedItem *other4=new partArrival(20,0,s);
    
    //inserting
    p->insert(other);
    p->insert(other2);
    p->insert(other3);
    p->insert(other4);
    
    REQUIRE(dynamic_cast<Event*>(p->getFront())->getTime()<dynamic_cast<Event*>(other2)->getTime());//checking ordered insertion
   
}
TEST_CASE("Inserting different events  and checking they are in sorted order","[PriorityQueue]"){
    PriorityQueue *p=new PriorityQueue();
    Simulation *s=new Simulation();
    
    //creating event objects
    OrderedItem *endAssemb=new endAssembly(50,s); // eventtime is 50
    OrderedItem *startAssemb=new startAssembly(20,10,s);//eventtime is 20
    OrderedItem *product =new productArrival(30,s);//eventtime is 30
    
    //inserting into priority queue
    p->insert(endAssemb);
    p->insert(startAssemb);
    p->insert(product);
    
    REQUIRE(p->getSize()==3); //checking size of the queue
    REQUIRE(dynamic_cast<startAssembly*>(p->getFront())->getStartTime()<dynamic_cast<productArrival*>(product)->getProductTime());//checking front is smaller or not
}
