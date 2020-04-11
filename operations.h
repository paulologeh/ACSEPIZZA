#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <ctime>

using namespace std;

// struct vegOrder
// {
// 	int readyTime;
// 	time_t orderTime;
// 	int toppings[9];
// 	bool pizzaType;
// 	int orderNumber;
// 	time_t ovenTime;
// };

struct order
{
	time_t readyTime;
	time_t orderTime;
	time_t ovenTime;
	int orderNumber;
	int toppings[9];
	string pizzaType;
};

class operations
{
private:
	bool vegOven;
	bool regOven;
	time_t lastReadyTimeVeg;
	time_t lastReadyTimeReg;
	ofstream logs;
	queue<order> regRoll;
	queue<order> vegRoll;

public:
	time_t calculatePrepTime(int);
	bool vegOvenReady(time_t);
	bool regOvenReady(time_t);
	void generateOrder(time_t, int);
	void vegOrderComplete(time_t);
	void regOrderComplete(time_t);
	void logging(string);
};
