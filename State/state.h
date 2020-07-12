#pragma once
#include <QDebug>

class GumballMachine;
class State
{
public:
	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;
	virtual QString toString() = 0;
};

class NoQuarterState : public State
{
private:
	GumballMachine* gumballMachine;

public:
	NoQuarterState(GumballMachine* gumballMachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
	QString toString() override;
};

class HasQuarterState : public State
{
private:
	GumballMachine* gumballMachine;

public:
	HasQuarterState(GumballMachine* gumballMachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
	QString toString() override;
};

class SoldState : public State
{
private:
	GumballMachine* gumballMachine;

public:
	SoldState(GumballMachine* gumballMachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
	QString toString() override;
};

class SoldOutState : public State
{
private:
	GumballMachine* gumballMachine;

public:
	SoldOutState(GumballMachine* gumballMachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
	QString toString() override;
};

class WinnerState : public State
{
private:
	GumballMachine* gumballMachine;

public:
	WinnerState(GumballMachine* gumballMachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
	QString toString() override;
};