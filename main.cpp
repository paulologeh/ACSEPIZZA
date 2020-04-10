#include <iostream>
#include "simulation.h"



 int main()
 {
    simulation ACSE;
	ACSE.pizza.logging("\n*********** NEW SIMULATION ****************");
    ACSE.printACSE();
	
 	std::cout << "Welcome to ACSE Pizza\n";
 	std::cout << "This program simulates orders from our customers for 30 minutes\n";
 	std::cout << "The program will start now. Cheers \n\n";	 
	
    ACSE.simulate();

 	return 0;
 }

