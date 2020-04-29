CC=clang++
CFLAGS=--std=c++11



objects = Event.o Simulation.o ListItem.o Node.o OrderedItem.o partArrival.o PriorityQueue.o Queue.o startAssembly.o PartNumber.o endAssembly.o productArrival.o 
all: A2main.o $(objects)
	 $(CC) $(CFLAGS) -o A2 $< $(objects)

test: unitTest.o $(objects)
	$(CC) $(CFLAGS) -o U2 $< $(objects)  


%.o: %.cpp
	 $(CC) -c -o $@ $< $(CFLAGS)
Clean:
	-rm *.o $(objects)
