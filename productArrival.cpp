
#include "Simulation.h"
#include "startAssembly.h"
#include "productArrival.h"

productArrival::productArrival(int time,Simulation *s):Event(time,s){}//constructor

void productArrival:: processEvent(){
    sim->finishStation(1);
    cout<<"At time:"<<getTime()<<", productArrival event will occur"<<endl;
}//processEvent

int productArrival::getProductTime(){
    return getTime();
}//getTime
