#include "context.h"
#include <iostream>

int main(int argc, char *argv[])
{
	GumballMachine* gumballMachine = new GumballMachine(5);
	std::cout << gumballMachine->toString().toStdString().c_str();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
	std::cout << gumballMachine->toString().toStdString().c_str();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
	std::cout << gumballMachine->toString().toStdString().c_str();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
	std::cout << gumballMachine->toString().toStdString().c_str();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
	std::cout << gumballMachine->toString().toStdString().c_str();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
	std::cout << gumballMachine->toString().toStdString().c_str();

    return 0;
}
