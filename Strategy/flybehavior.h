#pragma once
#include <QDebug>

class FlyBehavior
{
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
	void fly() override { qDebug() << "I'm flying!!"; }
};

class FlyNoWay : public FlyBehavior
{
public:
	void fly() override { qDebug() << "I can't fly"; }
};

class FlyRocketPowered : public FlyBehavior
{
public:
	void fly() override { qDebug() << "I'm flying with a rocket!"; }
};
