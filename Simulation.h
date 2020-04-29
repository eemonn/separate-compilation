#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class PriorityQueue; // Priority Queue
class Queue; // Queue class - provided to you
class Event; // Event - given to you. 
class PartNumber;
class ListItem;
class Simulation {
private:
        ifstream ifile; // input file to read.
        int simulationTime; // what is the current time of the simulation?
        PriorityQueue *eventList; // priority queue of Events.
        Queue* productQueue; // queue of partially assembled products (for finishing station).
        Queue** partQueues; // *array* of queues of parts for the stations.
        int  mainAssemblyTime; //  how long does the main station take?
        int  finishingAssemblyTime; //  how long does the main station take?
        bool mainBusy; // is the main station busy?
        bool finishingBusy; // is the finishing station busy?
        int timeForfinishStation;
        int partNum;//partnum for part(e.g 0,1,2)
    
        //need for printing statistics
        int completelyAssembleditem; // how many product completely assembled
        float averageTime; //average buildtime
   

public:
    Simulation();
    //getting assembly time
    int getmainAssemblyTime();
    int getfinishingAssemblyTime();
    
    //add to queue
    void addToqueue(ListItem *);
	// you need methods to manipulate product and part queues.
    void mainStation(int,int,int );
    void finishStation(int );
   
  
    int getSimulationTime();
    void setSimulationTime(int time);

    // main method for driving the simulation
    void runSimulation(char *fileName);

	//add an event to event queue.
	void addEvent (Event*); 

	// read next arrival from file and add it to the event queue. 
    void getNextArrival();
	
	// getters and setters for station statuses.
	bool isMainBusy();
	bool isFinishingBusy();
	void setMainStatus(bool);
	void setFinishingStatus(bool);

};// class Simulation
