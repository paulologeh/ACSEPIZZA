//Builds functions to generate order, calculate preparation time, oven ready status and order complete fucntion
#include "operations.h"
#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <ctime>

#define PREP_TIME 180

using namespace std;

void operations::generateOrder(time_t currentTime, int orderID)
{
	cout << "Please choose Pizza topping. You are only allowed a maximum of 9\n";
	cout << "1. Pepperoni 2. Sausage 3. Mushrooms 4. Peppers 5. Chicken 6. Beef 7. Pinapple 8. Sweetcorn 9. Bacon\n";
	cout << "Choose topping by entering the topping number then pressing Enter\n";
	cout << "Enter 0 to stop entering toppings" << endl;

	int toppingsNumber = 0, choices[9], entered;
	bool vegetarian = true, userInput = true;
	srand(time(NULL));

	do
	{
		// simulate the order toppings as well
		if (toppingsNumber == 0)
		{
			entered = rand() % 10 + 1;
		}
		else
		{
			entered = rand() % 10;
		}

		if (entered == 0 || toppingsNumber >= 9)
		{
			userInput = false;
		}
		else
		{
			choices[toppingsNumber] = entered;
			if (choices[toppingsNumber] == 1 || choices[toppingsNumber] == 2 || choices[toppingsNumber] == 5 || choices[toppingsNumber] == 6 || choices[toppingsNumber] == 9)
			{
				vegetarian = false; // If option 1, 3, 5, 6 or 8 selected then its not vegetarian
			}
			toppingsNumber++;
		}

	} while (userInput);
	cout << "Your Order is Being Processed .........." << endl;

	order regularOrder;	   // non vegetarian queue
	order vegetarianOrder; // vegetarian queue
	stringstream currentTimeSS;
	vegetarian = true; // remove later

	if (vegetarian)
	{
		currentTimeSS << currentTime;
		string message = "|NewOrder|Pizza=Vegetarian|Time=" + currentTimeSS.str() + "|orderID=" + to_string(orderID) + "|Toppings="; // trying to use FIX message formats

		for (int n = 0; n < toppingsNumber; n++) // put toppings in struct
		{
			vegetarianOrder.toppings[n] = choices[n];
			message += to_string(choices[n]) + " ";
		}

		vegetarianOrder.pizzaType = "Vegetarian";
		vegetarianOrder.orderNumber = orderID;
		vegetarianOrder.orderTime = currentTime;
		vegOven = vegOvenReady(currentTime);

		if (vegOven)
		{
			// oven is ready
			vegetarianOrder.ovenTime = vegetarianOrder.orderTime + calculatePrepTime(toppingsNumber);
		}
		else
		{
			vegetarianOrder.ovenTime = lastReadyTimeVeg; // get time the oven will be available
			message += ("|Note=Oven is in use until " + to_string(lastReadyTimeVeg));
		}

		vegetarianOrder.readyTime = vegetarianOrder.ovenTime + PREP_TIME;
		message += ("|OrderReadyTime=" + to_string(vegetarianOrder.readyTime) + "|");
		vegRoll.push(vegetarianOrder);
		logging(message);
		cout << message << endl;
	}
	else
	{
		currentTimeSS << currentTime;
		string message = "|NewOrder|Pizza=Regular|Time=" + currentTimeSS.str() + "|orderID=" + to_string(orderID) + "|Toppings="; // trying to use FIX message formats

		for (int n = 0; n < toppingsNumber; n++) // put toppings in struct
		{
			regularOrder.toppings[n] = choices[n];
			message += to_string(choices[n]) + " ";
		}

		regularOrder.pizzaType = "Regular";
		regularOrder.orderNumber = orderID;
		regularOrder.orderTime = currentTime;
		regOven = regOvenReady(currentTime);

		if (regOven)
		{
			// oven is ready
			regularOrder.ovenTime = regularOrder.orderTime + calculatePrepTime(toppingsNumber);
		}
		else
		{
			regularOrder.ovenTime = lastReadyTimeReg; // get time the oven will be available
			message += ("|Note=Oven is in use until " + to_string(lastReadyTimeReg));
		}

		regularOrder.readyTime = regularOrder.ovenTime + PREP_TIME;
		message += ("|OrderReadyTime=" + to_string(regularOrder.readyTime) + "|");
		regRoll.push(regularOrder);
		logging(message);
		cout << message << endl;
	}
}

time_t operations::calculatePrepTime(int toppingsNumber)
{
	// time = baseTime + customerTime + toppingsTime + pizzasaucetime;
	return (30 + 30 + (toppingsNumber * 5) + 30);
}

bool operations::vegOvenReady(time_t currentTime)
{
	if (vegRoll.empty())
	{
		return true;
	}
	else
	{
		lastReadyTimeVeg = vegRoll.back().readyTime;
		return currentTime >= lastReadyTimeVeg;
	}
}

bool operations::regOvenReady(time_t currentTime)
{
	if (regRoll.empty())
	{
		return true;
	}
	else
	{
		lastReadyTimeReg = regRoll.back().readyTime;
		return currentTime >= lastReadyTimeReg;
	}
}

void operations::regOrderComplete(time_t currentTime)
{
	if (currentTime >= regRoll.front().readyTime && !regRoll.empty()) // has current time passed the order time of the oldest element in the queue
	{
		string message = "|OrderComplete|Pizza=" + regRoll.front().pizzaType + "|orderID=" + to_string(regRoll.front().orderNumber) + "|CompletedTime=" + to_string(currentTime) + "|";
		logging(message);
		cout << message << endl;
		regRoll.pop();
	}
}

void operations::vegOrderComplete(time_t currentTime)
{
	if (currentTime >= vegRoll.front().readyTime && !vegRoll.empty()) // has current time passed the order time of the oldest element in the queue
	{
		string message = "|OrderComplete|Pizza=" + vegRoll.front().pizzaType + "|orderID=" + to_string(vegRoll.front().orderNumber) + "|CompletedTime=" + to_string(currentTime) + "|";
		logging(message);
		cout << message << endl;
		vegRoll.pop();
	}
}

void operations::logging(string message)
{
	logs.open("acse_pizza.log", ios::app);
	logs << message << endl;
	logs.close();
}