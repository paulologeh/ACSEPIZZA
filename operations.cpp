#include "operations.h"
#include <string>
#include <sstream>
#include <iostream>
#include <queue>
#include <ctime>

#define OVEN_TIME 180

using namespace std;

void operations::generateOrder(time_t currentTime, int orderID, bool mode)
{
	cout << "Please choose Pizza topping. You are only allowed a maximum of 9\n";
	cout << "1. Pepperoni 2. Sausage 3. Mushrooms 4. Peppers 5. Chicken 6. Beef 7. Pinapple 8. Sweetcorn 9. Bacon\n";
	cout << "Choose topping by entering the topping number then pressing Enter\n";
	cout << "Enter 0 to stop entering toppings if you want less than 9 toppings" << endl;

	int toppingsNumber = 0, choices[9], entered;
	bool vegetarian = true, userInput = true;
	srand(time(NULL));

	// Enter order details
	do
	{
		if (toppingsNumber == 0)
		{
			if (mode)
			{
				entered = 1 + rand() % 9; // generate between 1 and 9 on first entry
			}
			else
			{
				cin >> entered;
			}
		}
		else
		{
			if (mode)
			{
				entered = rand() % 10; // generate between 0 and 9 on other entries
			}
			else
			{
				cin >> entered;
			}
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
		vegOven = ovenReady(currentTime, vegRoll);

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

		vegetarianOrder.readyTime = vegetarianOrder.ovenTime + OVEN_TIME;
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
		regOven = ovenReady(currentTime, regRoll);

		if (regOven) // if oven is ready
		{
			regularOrder.ovenTime = regularOrder.orderTime + calculatePrepTime(toppingsNumber);
		}
		else
		{
			regularOrder.ovenTime = lastReadyTimeReg; // get time the oven will be available
			message += ("|Note=Oven is in use until " + to_string(lastReadyTimeReg));
		}

		regularOrder.readyTime = regularOrder.ovenTime + OVEN_TIME;
		message += ("|OrderReadyTime=" + to_string(regularOrder.readyTime) + "|");
		regRoll.push(regularOrder);
		logging(message);
		cout << message << endl;
	}
}

time_t operations::calculatePrepTime(int toppingsNumber)
{
	/*
	time = baseTime + customerTime + toppingsTime + pizzasaucetime;
	baseTime is time to prepare the base (30 seconds)
	customerTime is time for the person to make order (30 seconds)
	toppingsTime is the time to add each topping (5 seconds)
	pizzasaucetime is the time to add pizza sauce (30 seconds)
	*/
	return (30 + 30 + (toppingsNumber * 5) + 30);
}

bool operations::ovenReady(time_t currentTime, queue<order> &Roll)
{
	if (Roll.empty()) // when no orders are in the queue
	{
		return true;
	}
	else
	{
		if (Roll.back().pizzaType == "Vegetarian") // veterian queue
		{
			lastReadyTimeVeg = Roll.back().readyTime;
			return currentTime >= lastReadyTimeVeg;
		}
		else
		{
			lastReadyTimeReg = Roll.back().readyTime;
			return currentTime >= lastReadyTimeReg;
		}
	}
}

void operations::orderComplete(time_t currentTime)
{
	if (!vegRoll.empty() && currentTime >= vegRoll.front().readyTime) // has current time passed the order time of the oldest element in the queue
	{
		time_t waitTime = currentTime - vegRoll.front().orderTime;
		string message = "|OrderComplete|Pizza=" + vegRoll.front().pizzaType + "|orderID=" + to_string(vegRoll.front().orderNumber) + "|WaitTime=" + to_string(waitTime) + "|CompletedTime=" + to_string(currentTime) + "|";
		logging(message);
		cout << message << endl;
		vegRoll.pop();
	}
	if (!regRoll.empty() && currentTime >= regRoll.front().readyTime) // has current time passed the order time of the oldest element in the queue
	{
		time_t waitTime = currentTime - regRoll.front().orderTime;
		string message = "|OrderComplete|Pizza=" + regRoll.front().pizzaType + "|orderID=" + to_string(regRoll.front().orderNumber) + "|WaitTime=" + to_string(waitTime) + "|CompletedTime=" + to_string(currentTime) + "|";
		logging(message);
		cout << message << endl;
		regRoll.pop();
	}
}

void operations::logging(string message)
{
	logs.open("acse_pizza.log", ios::app); // open log file for appending
	logs << message << endl;
	logs.close();
}
