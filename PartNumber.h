
#ifndef PartNumber_h
#define PartNumber_h
#include "ListItem.h"
class PartNumber:public ListItem{
private:
    int partNo;
    int arrivaltime;
public:
    PartNumber(int,int );//constructor
    int getPartno();
    int getArrivaltime();
};
#endif /* PartNumber_h */
