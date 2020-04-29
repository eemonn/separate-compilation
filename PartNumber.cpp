#include "PartNumber.h"

PartNumber::PartNumber(int num,int arrival):partNo(num),arrivaltime(arrival){}//constructor
int PartNumber::getPartno(){return partNo;}
int PartNumber::getArrivaltime(){return arrivaltime;}
