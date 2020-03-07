#include"simulation.h"
#include<string.h>
//Contains simulation function and function to determine if customer has made an order


#include<iostream>
#include<cstdlib>
using namespace std;

void simulation::simulateTime()
{	
	for(currentTime=1; currentTime<=1800; currentTime++) // Max 1800 seconds
	{
		placeOrder=determineOrder(); // calls function to determine order and return in placeOrder
		if(placeOrder==true)
		{
			cout<<"Customer has made order "<<currentTime<<"s"<<endl;
			cout<<"Please prepare pizza base "<<endl;
			pizza.generateOrder(currentTime);		 // Calls function to generate order
			
		}		
		pizza.regOrderComplete(currentTime); // checks non vegetarian queue to see if order is complete
	    pizza.vegOrderComplete(currentTime); // check vegetarian queue to see if order is complete
	} 
}

bool simulation::determineOrder()
{	
    int value;
	if(currentTime!=0)
	{
	value=(rand() % 60); // generates random number from 1 to 60
	srand(currentTime);
    }
    else
    {
    	cout<<"Time Initiated"<<endl;
	}
	
	if(value==20) // Choose a random number out of 60. So chance of choosing 25 in 60 is 1 in 60
	{
		return true;
	}
	else
	{
		return false;
	}
}

