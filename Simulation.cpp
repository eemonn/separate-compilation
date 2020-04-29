#include "Simulation.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "PartNumber.h"
#include "partArrival.h"
#include "ListItem.h"
#include "startAssembly.h"

Simulation::Simulation(){
    eventList=new PriorityQueue();
    productQueue=new Queue();
  
    partQueues=new Queue*[3];
    partQueues[0]=new Queue();
    partQueues[1]=new Queue();
    partQueues[2]=new Queue();
    completelyAssembleditem=0;
    averageTime=0;
   
}//constructor

void Simulation::runSimulation(char *fileName)
{
   
    Event *s;
    Event *e;
    
    //opening data file
    ifile.open(fileName);
    ifile>>mainAssemblyTime>>finishingAssemblyTime; //storing mainStation and finishStation assemblytime
    ifile>>simulationTime>>partNum;//reading next line
    
    
    e=new partArrival(partNum,simulationTime,this);
    eventList->insert(e); //putting in the eventlist
    
    //event driven loop
    while(!eventList->isEmpty()&& !ifile.eof()){
        s=dynamic_cast<Event*>(eventList->dequeue());
        s->processEvent();
         
    }
 
    //print out some statistics
    cout<<"\nprinting Statistics: "<<endl;
    cout<<"Total completely assembled product is: "<<completelyAssembleditem<<endl;
    cout<<"AverageTime is: "<<(float)(averageTime/completelyAssembleditem)<<endl;
    cout<<"PartZero left with: "<<partQueues[0]->getSize()<<" items"<<endl;
    cout<<"PartOne left with: "<<partQueues[1]->getSize()<<" items"<<endl;
    cout<<"PartTwo left with: "<<partQueues[2]->getSize()<<" items"<<endl;
    cout<<"Partially Assembled product left with: "<<productQueue->getSize()<<" items"<<endl;

}//runSimulation

int Simulation::getSimulationTime(){
    return simulationTime;
}//getSimulationtime

void Simulation::setSimulationTime(int time){
    simulationTime=time;
}//setSimulationtime

void Simulation::mainStation(int time,int partnum,int pos){

    Event *e;
    PartNumber *p;

    //mainStation will work for partArrival event
    if(pos==1){
    
    //checking both parts are available to assembly or not
    if(!partQueues[0]->isEmpty() && !partQueues[1]->isEmpty()){
        
       e=new startAssembly(time,mainAssemblyTime,this);
        eventList->insert(e);
        
        
        // creatiing new partially assembled product(P0+P1->P3)
        
        if((dynamic_cast<PartNumber*>(partQueues[0]->getFront())->getArrivaltime())< (dynamic_cast<PartNumber*>(partQueues[1]->getFront())->getArrivaltime()))
      
            p=new PartNumber(3,dynamic_cast<PartNumber*>(partQueues[0]->getFront())->getArrivaltime());
           else
               p=new PartNumber(3,dynamic_cast<PartNumber*>(partQueues[1]->getFront())->getArrivaltime());
            
            productQueue->enqueue(p); // adding partial assembly product to product queue
            
    }
    else if(partnum==0){
        p=new PartNumber(partnum,time);
        partQueues[0]->enqueue(p);
    }
    else if(partnum==1){
        p=new PartNumber(partnum,time);
        partQueues[1]->enqueue(p);
    }
}
    
    
    //mainstation will work for endAssembly event
    if(pos==2){
       
        //dequeueing part0 and part1
        partQueues[0]->dequeue();
        partQueues[1]->dequeue();
        
        if(!partQueues[0]->isEmpty()&&!partQueues[1]->isEmpty())
            e=new startAssembly(time,mainAssemblyTime,this);
    }
   
}//mainStation


void Simulation::finishStation(int pos){
    Event *e;
   
    if(pos==1){//finishStation will work for product arrival Event
    
    //checking proper parts are available for this station(e.g. partial assembled product and partnumber 2 )
    if(!partQueues[2]->isEmpty()&&!productQueue->isEmpty()){
        
        if(dynamic_cast<PartNumber*>(partQueues[2]->getFront())->getArrivaltime() > dynamic_cast<PartNumber*>(productQueue->getFront())->getArrivaltime())
            timeForfinishStation=dynamic_cast<PartNumber*>(partQueues[2]->getFront())->getArrivaltime();
        else
            timeForfinishStation=dynamic_cast<PartNumber*>(productQueue->getFront())->getArrivaltime();
        
        e= new startAssembly(timeForfinishStation,finishingAssemblyTime,this);
        eventList->insert(e);
    }
    
    }
    
    if(pos==2){
        //claculating statistics for endAssembly event.
       
        if(!partQueues[2]->isEmpty()&&!productQueue->isEmpty()){
            
            completelyAssembleditem++;
        averageTime=averageTime+(dynamic_cast<PartNumber*>(productQueue->getFront())->getArrivaltime())+(dynamic_cast<PartNumber*>(partQueues[2]->getFront())->getArrivaltime());
        
        productQueue->dequeue();
        partQueues[2]->dequeue();
        }
    
    }
}//finishStation
                              


void Simulation::addEvent(Event *e){
        eventList->insert(e);
}//addEvent will add event to eventlist


int Simulation:: getmainAssemblyTime(){
        return mainAssemblyTime;
}//getmainAssemblyTime

int Simulation::getfinishingAssemblyTime(){
        return finishingAssemblyTime;
}//getfinishingAssemlyTime
                              
                              
bool Simulation::isMainBusy(){
    return mainBusy;
}//isMainBusy

bool Simulation::isFinishingBusy(){
    return finishingBusy;
}//isFinishingBusy

//part number(P0,P1,P2) is adding to respective queues
void Simulation::addToqueue(ListItem *part){
    PartNumber *p=dynamic_cast<PartNumber*>(part);
    if(p->getPartno()==0){
        partQueues[0]->enqueue(p);
    }
    else if(p->getPartno()==1){
       partQueues[1]->enqueue(p);
    }
    else if(p->getPartno()==2){
        partQueues[2]->enqueue(p);
    }
}//addToqueue
                              
void Simulation::getNextArrival(){
    Event *e;
    ifile>>simulationTime>>partNum;
    e=new partArrival(partNum,simulationTime,this);
    this->eventList->insert(e);
  
}//getNextArrival

void Simulation::setMainStatus(bool isBusy){
    mainBusy=isBusy;
}//setMainStatus

void Simulation::setFinishingStatus(bool isBusy){
    finishingBusy=isBusy;
}//setFinnishingStatus
        

