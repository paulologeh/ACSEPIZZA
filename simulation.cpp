#include <iostream>
#include <ctime>
#include "simulation.h"

#define MAX_TIME 500
#define PRINT_TIME 5
#define INTERVAL 1

using namespace std;

void simulation::simulate()
{
	time(&startTime);
	time(&currentTime);
	time(&time2PrintTime);
	time(&T);
	timeDifference = difftime(currentTime, startTime);

	orderID = 0;
	srand(time(NULL));
	while (timeDifference < MAX_TIME)
	{
		time(&currentTime);
		timeDifference = difftime(currentTime, startTime);

		if (difftime(currentTime, T) >= INTERVAL) // Sets simulation time to intervals of INTERVAL
		{
			isOrder = rand() % 60 + 1;		   // generate random number every second
			if (isOrder == 28 || isOrder == 5) // 28 is actually quite rare
			{
				cout << "Order placed after " << timeDifference << " seconds" << endl;
				cout << "Please prepare Pizza Base " << endl;
				orderID++;
				pizza.generateOrder(timeDifference, orderID);
			}

			if (difftime(currentTime, time2PrintTime) >= PRINT_TIME)
			{
				time(&time2PrintTime); // reset print time
				cout << "\nTime Elapsed is " << timeDifference << " seconds ..." << endl;
			}

			time(&T); // Reset time interval
			pizza.orderComplete(timeDifference);
		}
	}
}

void simulation::complete()
{
	cout << "Simulation is complete\n";
}

void simulation::printACSE()
{
	cout << "000000"
			  << "  000000"
			  << "    000000"
			  << "    000000\n";
	cout << "0    0"
			  << "  0     "
			  << "    0     "
			  << "    0     \n";
	cout << "000000"
			  << "  0     "
			  << "    000000"
			  << "    000000\n";
	cout << "0    0"
			  << "  0     "
			  << "         0"
			  << "    0     \n";
	cout << "0    0"
			  << "  000000"
			  << "    000000"
			  << "    000000\n";
	cout << "\n";
	cout << "000000  "
			  << "  00    "
			  << "    000000"
			  << "    000000"
			  << "    000000\n";
	cout << "0    0  "
			  << "  00    "
			  << "        00"
			  << "        00"
			  << "    0    0\n";
	cout << "000000  "
			  << "  00    "
			  << "       00 "
			  << "       00 "
			  << "    000000\n";
	cout << "0       "
			  << "  00    "
			  << "      00  "
			  << "      00  "
			  << "    0    0\n";
	cout << "0       "
			  << "  00    "
			  << "    000000"
			  << "    000000"
			  << "    0    0\n";
	cout << "\n";
}