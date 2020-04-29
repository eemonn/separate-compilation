#ifndef endAssembly_h
#define endAssembly_h
#include "Event.h"
class productArrival;
class startAssembly;

class endAssembly:public Event{
public:
    using Event::getTime; //superclass getTime method
    endAssembly(int, Simulation*);//constructor
    void processEvent() ;//polymorphic method
};

#endif /* endAssembly_h */
