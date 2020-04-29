#include "Simulation.h"
#include "startAssembly.h"
#include "productArrival.h"
#include "endAssembly.h"

endAssembly::endAssembly(int endtime,Simulation *s):Event(endtime,s){}//constructor

void endAssembly::processEvent(){
    Event *e;
    e=new productArrival(getTime(),sim);//creating product arrival event here
    sim->addEvent(e);
    
    
    cout<<"At time:"<<getTime() << ", end assembly event occurs"<<endl;
    sim->mainStation(getTime(),0,2);
    sim->finishStation(2);

}//processEvent
