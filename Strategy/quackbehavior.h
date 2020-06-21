#pragma once
#include <QDebug>

class QuackBehavior
{
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
	void quack() override { qDebug() << "Quack"; }
};

class MuteQuack : public QuackBehavior
{
public:
	void quack() override { qDebug() << "<< Silence >>"; }
};

class Squeak : public QuackBehavior
{
public:
	void quack() override { qDebug() << "Squeak"; }
};
