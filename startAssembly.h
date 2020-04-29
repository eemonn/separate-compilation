#ifndef startAssembly_h
#define startAssembly_h
#include "Event.h"
class endAssembly;

class startAssembly:public Event{
private:
    int currentTime;
    int assemblyTime;
    Simulation *s;
public:
    using Event::getTime;//calling superclass method
    startAssembly(int, int,Simulation*);//constructor
    void processEvent();//polymorphic method
    int getAssemblytime();
    int getStartTime();
};


#endif /* startAssembly_h */
