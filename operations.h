#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <ctime>

using namespace std;

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
	bool ovenReady(time_t, queue<order> &);
	void generateOrder(time_t, int, bool);
	void orderComplete(time_t);
	void logging(string);
};
