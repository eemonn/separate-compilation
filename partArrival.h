#ifndef partArrival_h
#define partArrival_h
#include "Event.h"

class startAssembly;

class partArrival:public Event{
    
private:
    int arrivalTime;
    int partNumber;
    int stationNumber;
    
   
public:
    using Event::getTime;//calling superclass getTime method
    partArrival(int,int,Simulation* );//constructor
    int getPartNumber();
    int getstationNumber();
    int getArrivaltime();
    void processEvent();//polymorphic method
};

#endif /* partArrival_h */
