#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <ctime>

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
	time_t orderTime;
	int toppings[9];
	bool pizzaType;
	int orderNumber;
	int ovenTime;
};


class operations
{
	private:
		queue <regOrder> regRoll;
		queue <vegOrder> vegRoll;
		int vegOven;
		int regOven;
		int lastReadyTimeVeg;
		int lastReadyTimeReg;
		ofstream logs;

	public:
		void generateOrder(time_t);
		int calculatePrepTime(int);
		int vegOvenReady(int);
		int regOvenReady(int);
		void vegOrderComplete(int);
		void regOrderComplete(int);
		void logging(string);
};
