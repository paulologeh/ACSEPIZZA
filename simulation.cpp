#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "simulation.h"

#define MAX_TIME 1800
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

	int isOrder, randSum = 0, orderCount = 0;
	srand (time(NULL));
	

	while ( timeDifference < MAX_TIME )
	{
		time(&currentTime);
		timeDifference = difftime(currentTime, startTime);
		
		if( difftime(currentTime, T) >= INTERVAL)  // Sets simulation time to intervals of INTERVAL
		{
			isOrder = rand() % 60 + 1;  // generate random number every second
			if (isOrder == 28) // 28 is actually quite rare
			{
				cout << "Order placed after " << timeDifference << " seconds" << endl;
				cout << "Please prepare Pizza Base " << endl;

				pizza.generateOrder(timeDifference);
				
				orderCount += 1;
			}
			
			if ( difftime(currentTime, time2PrintTime) >= PRINT_TIME )
			{
				time(&time2PrintTime); // reset print time
				cout << "\nTime Elapsed is " << timeDifference << " seconds ..." << endl;
			}

			time(&T); // Reset time interval

			// Logging
			randSum += isOrder;
		// 	string message = timeDifference + " seconds :: ";
		// 	message += " orderCount " + orderCount;
		// 	message += " average_random_no " + (randSum/timeDifference);
		// 	pizza.logging(message);
		}

	}


	// for(currentTime=1; currentTime<=MAX_TIME; currentTime++) // Max 1800 seconds
	// {
	// 	placeOrder=determineOrder(); // calls function to determine order and return in placeOrder
	// 	cout << "placeorder is " << placeOrder << endl;
	// 	cout << "current time " << currentTime << endl;
	// 	if(placeOrder==true)
	// 	{
	// 		cout<<"Customer has made order "<<currentTime<<"s"<<endl;
	// 		cout<<"Please prepare pizza base "<<endl;
	// 		pizza.generateOrder(currentTime);		 // Calls function to generate order
			
	// 	}		
	// 	pizza.regOrderComplete(currentTime); // checks non vegetarian queue to see if order is complete
	//     pizza.vegOrderComplete(currentTime); // check vegetarian queue to see if order is complete
	// } 
}

void simulation::printACSE()
{
     std::cout << "000000" << "  000000" << "    000000" << "    000000\n";
     std::cout << "0    0" << "  0     " << "    0     " << "    0     \n";
     std::cout << "000000" << "  0     " << "    000000" << "    000000\n";
     std::cout << "0    0" << "  0     " << "         0" << "    0     \n";
     std::cout << "0    0" << "  000000" << "    000000" << "    000000\n";
     std::cout << "\n";
     std::cout << "000000  " << "  00    " << "    000000" << "    000000" << "    000000\n";
     std::cout << "0    0  " << "  00    " << "        00" << "        00" << "    0    0\n";
     std::cout << "000000  " << "  00    " << "       00 " << "       00 " << "    000000\n";
     std::cout << "0       " << "  00    " << "      00  " << "      00  " << "    0    0\n";
     std::cout << "0       " << "  00    " << "    000000" << "    000000" << "    0    0\n";
     std::cout << "\n";
}