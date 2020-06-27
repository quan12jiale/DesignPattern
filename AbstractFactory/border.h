#pragma once
#include <QDebug>

class Border 
{
public:
	virtual void bordersay() = 0;
};

class MacBorder : public Border
{
public:
	void bordersay() override { qDebug() << "MacBorder"; }
};

class WinBorder : public Border 
{
public:
	void bordersay() override { qDebug() << "WinBorder"; }
};
