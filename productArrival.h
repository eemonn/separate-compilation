#ifndef productArrival_h
#define productArrival_h
#include "Event.h"

class startAssembly;

class productArrival:public Event{
public:
    using Event::getTime;//calling superclass method
    productArrival(int,Simulation *);//constructor
    void processEvent();//polymorphic method
    int getProductTime();
};


#endif /* productArrival_h */
