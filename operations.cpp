//Builds functions to generate order, calculate preparation time, oven ready status and order complete fucntion
#include "operations.h"
#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <ctime>

using namespace std;

void operations::generateOrder(time_t currentTime)
{
	cout << "Please choose Pizza topping. You are only allowed a maximum of 9" << endl;
	cout << "1. pepperoni  2. mushrooms  3. sausage  4. peppers  5. chicken  6. beef  7. pineapple 8. bacon 9. sweetcorn" << endl;
	cout << "Choose topping by typing entering the topping number then pressing Enter" << endl;
	// cout << "Enter 0 to stop entering toppings" << endl;
	int i = 0 , choices[9];
	bool vegetarian = true, userInput = true;
	do
	{
		int entered;
		cin >> entered;
		if (entered == 0 || i >= 9)
		{
			userInput = false;
		}
		else
		{
			choices[i] = entered;
			if(choices[i]==1 || choices[i]==3 || choices[i]==5 || choices[i]==6 || choices[i]==8)
			{
				vegetarian = false; // If option 1, 3, 5, 6 or 8 selected then its not vegetarian
			}
		}
		i++;
	} while (userInput);
	cout << "Your Order is Being Processed .........." << endl;
		
	regOrder regularOrder; // non vegetarian queue
	vegOrder vegetarianOrder; // vegetarian queue
 	
	 if(vegetarian)
 	{
// 		vegetarianOrder.orderTime=currentTime; // Sets order time into struct in queue
		stringstream currentTimeSS;
		currentTimeSS << currentTime;
		string message = " Vegetarian Pizza ordered at time: " + currentTimeSS.str();
		logging(message);
	 }
	 else
	 {
		stringstream currentTimeSS;
		currentTimeSS << currentTime;
		string message = " Regular Pizza ordered at time: " + currentTimeSS.str();
		logging(message);
	 }
	 
 //		if (vegeterian) {
 // 	cout << "Vegeterian Pizza ordered at : " << currentTime; // Displays order time
// 		vegetarianOrder.pizzaType=true;// true means vegetarian
// 		vegetarianOrder.orderNumber=100+ vegetarianOrder.orderTime; // Generates order number
// 		cout<<" OrderNumber: "<<vegetarianOrder.orderNumber;  // Displays order numer
// 		cout<<" Toppings are:";		
// 		for(int k=0;k<size;k++)
// 		{
// 			vegetarianOrder.toppings[k]=choices[k]; // Stores toppings in struct
// 			cout<<" "<<choices[k];   // Displays toppings chosen
// 		}	
// 		vegOven=vegOvenReady(currentTime);  // Passes current time into function and returns oven status

// 		if(vegOven==1) // Oven is ready
// 		{
// 			vegetarianOrder.ovenTime= vegetarianOrder.orderTime + calculatePrepTime(size); // calculates time to go into the oven
// 	    }
// 		else if(vegOven==0) // Oven is full
// 		{
// 			int vegdelay=(lastReadyTimeVeg-currentTime); // Calulcates delay for order
// 			// vegetarianOrder.ovenTime= vegetarianOrder.orderTime + calculatePrepTime(size) + (lastReadyTimeVeg-currentTime); // adds the delay to the oven time
// 			vegetarianOrder.ovenTime=lastReadyTimeVeg;
// 			cout<<" Pizza to be delayed by "<<vegdelay<<"s";
// 		}
		
// 		cout<<" Order is due to enter Oven at "<<vegetarianOrder.ovenTime; // Displays the oven time
// 		vegetarianOrder.readyTime=180+ vegetarianOrder.ovenTime; // Displays the ready time
// 		cout<<" Order will be ready at "<<vegetarianOrder.readyTime<<endl;	// Displays the ready time
// 		vegRoll.push(vegetarianOrder);		// Adds order to the end of the queue
// 	}
	
// 	else if(vegetarian==0)
// 	{
	
// 		cout<<"Pizza is not vegetarian OrderTime: "<<currentTime; // Displays order details
// 		regularOrder.orderTime=currentTime; // Sets ordertime to be the current time
// 		regularOrder.pizzaType=false; // false means no vegetarian
// 		regularOrder.orderNumber=100+ regularOrder.orderTime; // Generates the order number
// 		cout<<" OrderNumber: "<<regularOrder.orderNumber; // Displays order number
// 		cout<<" Toppings are:";
// 		for(int k=0;k<size;k++)
// 		{
// 			regularOrder.toppings[k]=choices[k]; // Stores toppings
// 			cout<<" "<<choices[k];  // Displays toppings
// 		}	
		
		
		
// 		regOven=regOvenReady(currentTime); // Passes current time into function to check if the oven is ready
// 		if(regOven==1) // Oven is available
// 		{
// 		regularOrder.ovenTime=regularOrder.orderTime  + calculatePrepTime(size);	 // calculates due oven time
// 		}
// 		else if(regOven==0) // Oven is unavailable
// 		{
// 		int regdelay;
// 		regdelay=(lastReadyTimeReg-currentTime); // calculates delay
// 		//regularOrder.ovenTime=regularOrder.orderTime  + calculatePrepTime(size) +(lastReadyTimeReg-currentTime); //adds delay to calculated oven time
// 		regularOrder.ovenTime=lastReadyTimeReg;
		
// 		cout<<" Pizza to be delayed by "<<regdelay<<"s"; // Shows delay times
// 		}
		
			
// 		cout<<" Order is due to enter Oven at "<<regularOrder.ovenTime; // Displays the oven due time
// 		regularOrder.readyTime=180+ regularOrder.ovenTime;  // calculates the ready time
// 		cout<<" Order will be ready at "<<regularOrder.readyTime<<endl; // displays the ready time
// 		regRoll.push(regularOrder); // adds order to the queue
// 	}
// 	cout<<" "<<endl;
}

int operations::calculatePrepTime(int size)
{
	int time;
	int baseTime=30;
	int customerTime=30;
	int toppingsTime;
	toppingsTime=(size*5) + 5; // Calculates topping time and adds pizza sauce time
	time = baseTime + customerTime + toppingsTime;
	return time;
}


int operations::vegOvenReady(int currentTime)
{
	
	lastReadyTimeVeg=vegRoll.front().readyTime; 
	if(lastReadyTimeVeg>1 && lastReadyTimeVeg<1800)
  {
	if(currentTime>=lastReadyTimeVeg) // Has current time reached the last recorded ready time?
	{
		return 1; // returns true, so oven is ready
	}
	else if(currentTime<lastReadyTimeVeg) // Is current time not reached the last recorded ready time?
	{
		return 0; // return false, so oven not ready
	}
  }
  else
  {
  	return 1;
  }

}
int operations::regOvenReady(int currentTime)
{
	lastReadyTimeReg=regRoll.front().readyTime;
	if(lastReadyTimeReg>1 && lastReadyTimeReg<1800)
	{
	if(currentTime>=lastReadyTimeReg) // Has current time reached the last recorded ready time?
	{
		return 1; // returns true, so oven is ready
	}
	else if(currentTime<lastReadyTimeReg) // Is current time not reached the last recorded ready time?
	{
		return 0;  // return false, so oven not ready
	}
    }
    else
    {
    	return 1;
	}
}


void operations::regOrderComplete(int currentTime)
{
	int time;
	time= regRoll.front().readyTime; // gets ready time in order at front of queue
	int order;
	order=regRoll.front().orderNumber; // gets order number at queue front
	if(time==currentTime && time!=0)
	{
		cout<<"Order Number "<<order<<" is ready"<<endl;
		regRoll.pop(); // pops order number that is complete outside
	}
	
}

void operations::vegOrderComplete(int currentTime)
{
	int time;
	time=vegRoll.front().readyTime; // gets ready time in order at front of queue
	int order;
	order=vegRoll.front().orderNumber; // gets order number at queue front
	if(time==currentTime && time!=0)
	{
		cout<<"Order Number "<<order<<" is ready"<<endl;
		vegRoll.pop(); // pops order number that is complete outside
	}	
}

void operations::logging(string message)
{
	logs.open("acse_pizza.log",ios::app);
	logs << message << endl;
	logs.close();
}