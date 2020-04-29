#include "Event.h"

Event::Event(int theTime, Simulation *theSim) :eventTime(theTime), sim (theSim) {}
Event::~Event() {}
int Event::getTime(){ return eventTime; }

int Event::compareTo(OrderedItem *other){
	
    Event *e=dynamic_cast<Event*>(other);
  
   if(this->eventTime<e->getTime()){
            return 1;
        }
        else{
            return 0;
        }
}// compareTo
