#pragma once
#include "component.h"

class CondimentDecorator : public Beverage
{
public:
	QString getDescription() const override = 0;
};

// Ä¦¿¨
class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* beverage) { this->beverage = beverage; }
	QString getDescription() const override { return beverage->getDescription() + ", Mocha"; }
	double cost() const override { return beverage->cost() + 0.2; }

private:
	Beverage* beverage;
};

// ¶¹½¬
class Soy : public CondimentDecorator
{
public:
	Soy(Beverage* beverage) { this->beverage = beverage; }
	QString getDescription() const override { return beverage->getDescription() + ", Soy"; }
	double cost() const override { return beverage->cost() + 0.15; }

private:
	Beverage* beverage;
};

// ÄÌÅİ
class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* beverage) { this->beverage = beverage; }
	QString getDescription() const override { return beverage->getDescription() + ", Whip"; }
	double cost() const override { return beverage->cost() + 0.1; }

private:
	Beverage* beverage;
};
