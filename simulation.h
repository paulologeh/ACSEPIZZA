#include <iostream>
#include <ctime>
#include "operations.h"

using namespace std;

class simulation
{
private:
	int orderID;
	int isOrder;
	time_t startTime, currentTime, time2PrintTime, T;
	time_t timeDifference;

public:
	void simulate();
	void printACSE();
	void complete();
	operations pizza;
};
