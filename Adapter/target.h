#pragma once
#include <QDebug>

class Duck
{
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

class MallardDuck : public Duck
{
public:
	void quack() override { qDebug() << "Quack"; }
	void fly() override { qDebug() << "I'm flying"; }
};
