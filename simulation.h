// header file string.h
// contains function to simulate time and determine order

#include <string.h>
#include <iostream>
#include <ctime>
#include "operations.h"

using namespace std;

class simulation
{
	private:
		time_t currentTime;
		int orderID;

	public:

		void simulate();
		void printACSE();
		operations pizza;


};
