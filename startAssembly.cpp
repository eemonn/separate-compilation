#include "Simulation.h"
#include "endAssembly.h"
#include "startAssembly.h"
startAssembly::startAssembly(int currTime,int time,Simulation *s):Event(currTime,s),assemblyTime(time){}//constructor
int startAssembly:: getStartTime(){return getTime();}
int startAssembly:: getAssemblytime(){return assemblyTime;}

void startAssembly::processEvent(){
    
    Event *e=new endAssembly(getTime()+assemblyTime,sim);
    sim->addEvent(e);
    cout<<"At time:"<<getTime()<<", startAssembly event will occur"<<endl;
    
}//processEvent
