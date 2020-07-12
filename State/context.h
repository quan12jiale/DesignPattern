#pragma once
#include <QDebug>

class State;
class GumballMachine
{
private:
	State* soldOutState;
	State* noQuarterState;
	State* hasQuarterState;
	State* soldState;
	State* winnerState;

public:
	State* state;
	int count;

public:
	GumballMachine(int numberGumballs);
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();

	void setState(State* state);
	State* getState();
	void releaseBall();
	int getCount();
	void refill(int count);

	State* getSoldOutState();
	State* getNoQuarterState();
	State* getHasQuarterState();
	State* getSoldState();
	State* getWinnerState();

	QString toString();
};

