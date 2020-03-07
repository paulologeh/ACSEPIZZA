// header file string.h
// contains function to simulate time and determine order

#include<string.h>
#include <iostream>
#include"operations.h"

using namespace std;

class simulation
{
	private:
		bool placeOrder; // defaults statuse is false
		int currentTime; // current time of the program
	public:
		
		bool determineOrder();
		void simulateTime();
		operations pizza;
		
		
};
