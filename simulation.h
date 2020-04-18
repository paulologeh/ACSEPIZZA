#include <iostream>
#include <ctime>
#include "operations.h"

class postSimulation
{
private:
	int randSum, randCount;

public:
	void initialise();
	void updateRands(int);
	int randomAverage();
};

class simulation
{
private:
	bool automatic;
	int orderID;
	int isOrder;
	time_t startTime, currentTime, time2PrintTime, T;
	time_t timeDifference;

public:
	void simulate();
	void printACSE();
	void complete();
	operations pizza;
	postSimulation benchmarks;
};