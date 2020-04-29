
**There are four different event sub classes - "partArrival","startAssembly","endAssembly" and "productArrival"

**Data structure class called "PriorityQueue"

**One "PartNumber"class to hold part number (P0,P1,P2 and partially assembled product) in the queue.

**Whole program is driven by the "Simulation" class that is implemented.

**Testing class called "unitTest"

**others class were given -"ListItem","Queue","A2main","Event","OrderdedItem","Node"

**All classes are in separate compilation(.h and .cpp ).





					*********************************************************
					instruction of how to do compile and test for the program
					*********************************************************

****In the makeFile there are two fields "all" and "test". 

***Command "make all" from command line will compile the program and creates an executable "A2" to see output of the program.

***To do unit testing use "make test" command and it will create an executable "U2" to see the test result.