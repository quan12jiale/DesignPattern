#include "state.h"
#include "context.h"
#include <QTime>

/**************************/
NoQuarterState::NoQuarterState(GumballMachine* gumballMachine)
{
	this->gumballMachine = gumballMachine;
}

void NoQuarterState::insertQuarter()
{
	qDebug() << "You inserted a quarter";
	gumballMachine->setState(gumballMachine->getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
	qDebug() << "You haven't inserted a quarter";
}

void NoQuarterState::turnCrank()
{
	qDebug() << "You turned, but there's no quarter";
}

void NoQuarterState::dispense()
{
	qDebug() << "You need to pay first";
}

QString NoQuarterState::toString()
{
	return "waiting for quarter";
}


/**************************/
HasQuarterState::HasQuarterState(GumballMachine* gumballMachine)
{
	this->gumballMachine = gumballMachine;
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
}

void HasQuarterState::insertQuarter()
{
	qDebug() << "You can't insert another quarter";
}

void HasQuarterState::ejectQuarter()
{
	qDebug() << "Quarter returned";
	gumballMachine->setState(gumballMachine->getNoQuarterState());
}

void HasQuarterState::turnCrank()
{
	qDebug() << "You turned...";
	int winner = qrand() % 5;
	if ((winner == 0) && (gumballMachine->getCount() > 1)) 
	{
		gumballMachine->setState(gumballMachine->getWinnerState());
	}
	else 
	{
		gumballMachine->setState(gumballMachine->getSoldState());
	}
}

void HasQuarterState::dispense()
{
	qDebug() << "No gumball dispensed";
}

QString HasQuarterState::toString()
{
	return "waiting for turn of crank";
}


/**************************/
SoldState::SoldState(GumballMachine* gumballMachine)
{
	this->gumballMachine = gumballMachine;
}

void SoldState::insertQuarter()
{
	qDebug() << "Please wait, we're already giving you a gumball";
}

void SoldState::ejectQuarter()
{
	qDebug() << "Sorry, you already turned the crank";
}

void SoldState::turnCrank()
{
	qDebug() << "Turning twice doesn't get you another gumball!";
}

void SoldState::dispense()
{
	gumballMachine->releaseBall();
	if (gumballMachine->getCount() > 0) {
		gumballMachine->setState(gumballMachine->getNoQuarterState());
	}
	else {
		qDebug() << "Oops, out of gumballs!";
		gumballMachine->setState(gumballMachine->getSoldOutState());
	}
}

QString SoldState::toString()
{
	return "dispensing a gumball";
}


/**************************/
SoldOutState::SoldOutState(GumballMachine* gumballMachine)
{
	this->gumballMachine = gumballMachine;
}

void SoldOutState::insertQuarter()
{
	qDebug() << "You can't insert a quarter, the machine is sold out";
}

void SoldOutState::ejectQuarter()
{
	qDebug() << "You can't eject, you haven't inserted a quarter yet";
}

void SoldOutState::turnCrank()
{
	qDebug() << "You turned, but there are no gumballs";
}

void SoldOutState::dispense()
{
	qDebug() << "No gumball dispensed";
}

QString SoldOutState::toString()
{
	return "sold out";
}


/**************************/
WinnerState::WinnerState(GumballMachine* gumballMachine)
{
	this->gumballMachine = gumballMachine;
}

void WinnerState::insertQuarter()
{
	qDebug() << "Please wait, we're already giving you a Gumball";
}

void WinnerState::ejectQuarter()
{
	qDebug() << "Please wait, we're already giving you a Gumball";
}

void WinnerState::turnCrank()
{
	qDebug() << "Turning again doesn't get you another gumball!";
}

void WinnerState::dispense()
{
	qDebug() << "YOU'RE A WINNER! You get two gumballs for your quarter";
	gumballMachine->releaseBall();
	if (gumballMachine->getCount() == 0) {
		gumballMachine->setState(gumballMachine->getSoldOutState());
	}
	else {
		gumballMachine->releaseBall();
		if (gumballMachine->getCount() > 0) {
			gumballMachine->setState(gumballMachine->getNoQuarterState());
		}
		else {
			qDebug() << "Oops, out of gumballs!";
			gumballMachine->setState(gumballMachine->getSoldOutState());
		}
	}
}

QString WinnerState::toString()
{
	return "despensing two gumballs for your quarter, because YOU'RE A WINNER!";
}
