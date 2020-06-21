#pragma once
#include "flybehavior.h"
#include "quackbehavior.h"

class Duck
{
public:
	virtual void display() = 0;
	void performFly() { flyBehavior->fly(); }
	void performQuack() { quackBehavior->quack(); }
	void swim() { qDebug() << "All ducks float, even decoys!"; }

	void setFlyBehavior(FlyBehavior* fb) { flyBehavior = fb; }
	void setQuackBehavior(QuackBehavior* qb) { quackBehavior = qb; }
protected:
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
};

// ÂÌÍ·Ñ¼
class MallardDuck : public Duck
{
public:
	MallardDuck() {
		quackBehavior = new Quack;
		flyBehavior = new FlyWithWings;
	}
	void display() override { qDebug() << "I'm a real Mallard duck"; }
};

// Ä£ÐÍÑ¼
class ModelDuck : public Duck
{
public:
	ModelDuck() {
		quackBehavior = new Quack;
		flyBehavior = new FlyNoWay;
	}
	void display() override { qDebug() << "I'm a model duck"; }
};
