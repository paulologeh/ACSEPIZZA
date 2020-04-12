#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "simulation.h"

#define MAX_TIME 500
#define PRINT_TIME 5
#define INTERVAL 1

using namespace std;

void simulation::simulate()
{
	time_t startTime, currentTime, time2PrintTime, T;
	time(&startTime);
	time(&currentTime);
	time(&time2PrintTime);
	time(&T);
	time_t timeDifference = difftime(currentTime, startTime);

	int isOrder, orderCount = 0;
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

				orderCount += 1;
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
	std::cout << "000000"
			  << "  000000"
			  << "    000000"
			  << "    000000\n";
	std::cout << "0    0"
			  << "  0     "
			  << "    0     "
			  << "    0     \n";
	std::cout << "000000"
			  << "  0     "
			  << "    000000"
			  << "    000000\n";
	std::cout << "0    0"
			  << "  0     "
			  << "         0"
			  << "    0     \n";
	std::cout << "0    0"
			  << "  000000"
			  << "    000000"
			  << "    000000\n";
	std::cout << "\n";
	std::cout << "000000  "
			  << "  00    "
			  << "    000000"
			  << "    000000"
			  << "    000000\n";
	std::cout << "0    0  "
			  << "  00    "
			  << "        00"
			  << "        00"
			  << "    0    0\n";
	std::cout << "000000  "
			  << "  00    "
			  << "       00 "
			  << "       00 "
			  << "    000000\n";
	std::cout << "0       "
			  << "  00    "
			  << "      00  "
			  << "      00  "
			  << "    0    0\n";
	std::cout << "0       "
			  << "  00    "
			  << "    000000"
			  << "    000000"
			  << "    0    0\n";
	std::cout << "\n";
}