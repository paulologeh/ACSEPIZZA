//operations.h header file
// Contains struct for order queues
//Contains methods to generate order , calculate preparation time,  check the oven and order complete function


#include <string.h>
#include <iostream>
#include<queue>
using namespace std;

struct vegOrder
{
	int readyTime;
	int orderTime;
	int toppings[9];
	bool pizzaType;
	int orderNumber;
	int ovenTime;		
};

struct regOrder
{
	int readyTime;
	int orderTime;
	int toppings[9];
	bool pizzaType;
	int orderNumber;
	int ovenTime;
};


class operations
{
	private:
		queue<regOrder>regRoll;
		queue<vegOrder>vegRoll;
		int vegOven;
		int regOven;
		int lastReadyTimeVeg;
		int lastReadyTimeReg;

	public:
		void generateOrder(int);
		int calculatePrepTime(int);
		int vegOvenReady(int);
		int regOvenReady(int);
		void vegOrderComplete(int);
		void regOrderComplete(int);
};
