//Builds functions to generate order, calculate preparation time, oven ready status and order complete fucntion
#include"operations.h"
#include<string.h>
#include<math.h>
#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

void operations::generateOrder(int currentTime)
{
	int choices[9];	string more; int i,size=1;
	regOrder anOrder; // non vegetarian queue
	vegOrder AnOrder; // vegetarian queue
	
	cout<<"Please choose Pizza topping. You are only allowed a maximum of 9"<<endl;
	cout<<"Choose topping by typing entering the number before it"<<endl;
	cout<<"1. pepperoni  2. mushrooms  3. sausage  4. peppers  5. chicken  6. beef  7. pineapple 8. bacon 9. sweetcorn"<<endl;

	for(i=0;i<9;i++)
	{
		cout<<"Please enter topping "; // Prompts user to input topping
		cin>>choices[i]; 
		cout<<"You enetered "<<choices[i]<<endl;  // Displays choice
		cout<<"Would you like to add more toppings? (yes/no)"<<endl;  // Prompts user for more topping choice
		cin>>more;
		if(more=="no") // if no more toppings
		{
		i=9;	// skip to end of the loop
		}
		else if(more=="yes") // if more toppings
		{
			size=size+1;  // stores number of toppings
		}
	}
	// Determine pizza type;
	int vegetarian=1; //Assumes vegetarian by default
	// If option 1, 3, 5, 6 or 8 selected then its not vegetarian
	int j,k;

	for(j=0;j<size;j++)
	{
		if(choices[j]==1 || choices[j]==3 || choices[j]==5 || choices[j]==6 || choices[j]==8)
		{
			vegetarian=0;
		}
	}	

	if(vegetarian==1) // Is vegetarian status unchanged
	{
		AnOrder.orderTime=currentTime; // Sets order time into struct in queue
		cout<<"Pizza is vegetarian  OrderTime: "<<currentTime; // Displays order time
		AnOrder.pizzaType=true;// true means vegetarian
		AnOrder.orderNumber=100+ AnOrder.orderTime; // Generates order number
		cout<<" OrderNumber: "<<AnOrder.orderNumber;  // Displays order numer
		cout<<" Toppings are:";		
		for(k=0;k<size;k++)
		{
			AnOrder.toppings[k]=choices[k]; // Stores toppings in struct
			cout<<" "<<choices[k];   // Displays toppings chosen
		}	
		vegOven=vegOvenReady(currentTime);  // Passes current time into function and returns oven status

		if(vegOven==1) // Oven is ready
		{
			AnOrder.ovenTime= AnOrder.orderTime + calculatePrepTime(size); // calculates time to go into the oven
	    }
		else if(vegOven==0) // Oven is full
		{
			int vegdelay=(lastReadyTimeVeg-currentTime); // Calulcates delay for order
			// AnOrder.ovenTime= AnOrder.orderTime + calculatePrepTime(size) + (lastReadyTimeVeg-currentTime); // adds the delay to the oven time
			AnOrder.ovenTime=lastReadyTimeVeg;
			cout<<" Pizza to be delayed by "<<vegdelay<<"s";
		}
		
		cout<<" Order is due to enter Oven at "<<AnOrder.ovenTime; // Displays the oven time
		AnOrder.readyTime=180+ AnOrder.ovenTime; // Displays the ready time
		cout<<" Order will be ready at "<<AnOrder.readyTime<<endl;	// Displays the ready time
		vegRoll.push(AnOrder);		// Adds order to the end of the queue
	}
	
	else if(vegetarian==0)
	{
	
		cout<<"Pizza is not vegetarian OrderTime: "<<currentTime; // Displays order details
		anOrder.orderTime=currentTime; // Sets ordertime to be the current time
		anOrder.pizzaType=false; // false means no vegetarian
		anOrder.orderNumber=100+ anOrder.orderTime; // Generates the order number
		cout<<" OrderNumber: "<<anOrder.orderNumber; // Displays order number
		cout<<" Toppings are:";
		for(k=0;k<size;k++)
		{
			anOrder.toppings[k]=choices[k]; // Stores toppings
			cout<<" "<<choices[k];  // Displays toppings
		}	
		
		
		
		regOven=regOvenReady(currentTime); // Passes current time into function to check if the oven is ready
		if(regOven==1) // Oven is available
		{
		anOrder.ovenTime=anOrder.orderTime  + calculatePrepTime(size);	 // calculates due oven time
		}
		else if(regOven==0) // Oven is unavailable
		{
		int regdelay;
		regdelay=(lastReadyTimeReg-currentTime); // calculates delay
		//anOrder.ovenTime=anOrder.orderTime  + calculatePrepTime(size) +(lastReadyTimeReg-currentTime); //adds delay to calculated oven time
		anOrder.ovenTime=lastReadyTimeReg;
		
		cout<<" Pizza to be delayed by "<<regdelay<<"s"; // Shows delay times
		}
		
			
		cout<<" Order is due to enter Oven at "<<anOrder.ovenTime; // Displays the oven due time
		anOrder.readyTime=180+ anOrder.ovenTime;  // calculates the ready time
		cout<<" Order will be ready at "<<anOrder.readyTime<<endl; // displays the ready time
		regRoll.push(anOrder); // adds order to the queue
	}
	cout<<" "<<endl;
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
