#include <iostream>
#include <ctime>
#include "simulation.h"

#define MAX_TIME 1800
#define ORDER_CUTOFF 1485
#define PRINT_TIME 5
#define INTERVAL 1

using namespace std;

void postSimulation::initialise()
{
	randSum = 0;
	randCount = 0;
}

void postSimulation::updateRands(int isOrder)
{
	randSum += isOrder;
	randCount++;
}

int postSimulation::randomAverage()
{
	return randSum / randCount;
}

void simulation::simulate()
{
	cout << "Enter 1 for automatic orders or 0 to manually enter orders" << endl;
	cin >> automatic;

	// Get initial times
	time(&startTime);
	time(&currentTime);
	time(&time2PrintTime);
	time(&T);
	timeDifference = difftime(currentTime, startTime);

	orderID = 0;
	srand(time(NULL));
	benchmarks.initialise();

	while (timeDifference < MAX_TIME)
	{
		time(&currentTime);
		timeDifference = difftime(currentTime, startTime);

		if (difftime(currentTime, T) >= INTERVAL) // Sets simulation time to intervals of INTERVAL
		{
			isOrder = rand() % 60 + 1; // generate random number every second
			benchmarks.updateRands(isOrder);

			// Generate new order if random number is 5/28 and time below order cutoff
			if ((isOrder == 28 || isOrder == 5) && timeDifference <= ORDER_CUTOFF)
			{
				cout << "Order placed after " << timeDifference << " seconds" << endl;
				cout << "Please prepare Pizza Base " << endl;
				orderID++;
				pizza.generateOrder(timeDifference, orderID, automatic);
			}

			if (difftime(currentTime, time2PrintTime) >= PRINT_TIME)
			{
				time(&time2PrintTime); // reset print time
				cout << "\nTime Elapsed is " << timeDifference << " seconds ...\n";
			}

			time(&T); // Reset time interval
			pizza.orderComplete(timeDifference);
		}
	}
}

void simulation::complete()
{
	cout << "Simulation is complete\n";
	cout << "Average Random Number: " << benchmarks.randomAverage() << endl;
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