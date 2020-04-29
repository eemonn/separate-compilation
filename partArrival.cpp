#include "PartNumber.h"
#include "Simulation.h"
#include "startAssembly.h"
#include "partArrival.h"
#include "Queue.h"
partArrival::partArrival(int partNum,int arrival,Simulation *s):Event(arrival,s ),partNumber(partNum){}//constructor

int partArrival::getPartNumber(){
    return partNumber;
}//getPartNumber

int partArrival::getstationNumber(){
    return stationNumber;
}//getstationNumber

void partArrival::processEvent(){
    //generating partnumber object and adding it to correspondance queue
    PartNumber *p=new PartNumber(partNumber,getTime());
    sim->addToqueue(p);
  
    
 if(partNumber==0 || partNumber==1){
    sim->mainStation(getTime(),partNumber,1);
    }
    else
    sim->finishStation(3);
            
    cout<<"At time:"<<getTime()<<", part "<<getPartNumber()<<" arrived."<<endl;
    
    sim->getNextArrival();//read next arrival from the file
}//processEvent

int partArrival::getArrivaltime(){
    return getTime();

}//getArrivaltime
