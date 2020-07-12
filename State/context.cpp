#include "context.h"
#include "state.h"

GumballMachine::GumballMachine(int numberGumballs)
{
	soldOutState = new SoldOutState(this);
	noQuarterState = new NoQuarterState(this);
	hasQuarterState = new HasQuarterState(this);
	soldState = new SoldState(this);
	winnerState = new WinnerState(this);

	this->state = soldOutState;
	this->count = numberGumballs;
	if (numberGumballs > 0) {
		state = noQuarterState;
	}
}

void GumballMachine::insertQuarter()
{
	state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
	state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
	state->turnCrank();
	state->dispense();
}

void GumballMachine::setState(State* state)
{
	this->state = state;
}

State* GumballMachine::getState()
{
	return state;
}

void GumballMachine::releaseBall()
{
	qDebug() << "A gumball comes rolling out the slot...";
	if (count != 0) {
		count = count - 1;
	}
}

int GumballMachine::getCount()
{
	return count;
}

void GumballMachine::refill(int count)
{
	this->count = count;
	state = noQuarterState;
}

State* GumballMachine::getSoldOutState()
{
	return soldOutState;
}

State* GumballMachine::getNoQuarterState()
{
	return noQuarterState;
}

State* GumballMachine::getHasQuarterState()
{
	return hasQuarterState;
}

State* GumballMachine::getSoldState()
{
	return soldState;
}

State* GumballMachine::getWinnerState()
{
	return winnerState;
}

QString GumballMachine::toString()
{
	QString result;
	result.append("\nMighty Gumball, Inc.");
	result.append("\nJava-enabled Standing Gumball Model");
	result.append("\nInventory: " + QString::number(count) + " gumball");
	if (count != 1) {
		result.append("s");
	}
	result.append("\n");
	result.append("Machine is " + state->toString() + "\n");
	return result;
}
