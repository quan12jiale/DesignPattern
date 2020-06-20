#pragma once
#include <QString>

class Beverage
{
public:
	virtual QString getDescription() const { return description; }
	virtual double cost() const = 0;

protected:
	QString description;
};

// Å¨Ëõ¿§·È
class Espresso : public Beverage
{
public:
	Espresso() { description = "Espresso"; }
	double cost() const override { return 1.99; }
};

// ×ÛºÏ¿§·È
class HouseBlend : public Beverage
{
public:
	HouseBlend() { description = "House Blend Coffee"; }
	double cost() const override { return 0.89; }
};

// Éî±º¿§·È
class DarkRoast : public Beverage
{
public:
	DarkRoast() { description = "Dark Roast Coffee"; }
	double cost() const override { return 0.99; }
};
