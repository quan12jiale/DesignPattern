#pragma once
#include <QDebug>

class Button
{
public:
	virtual void buttonsay() = 0;
};

class MacButton : public Button
{
public:
	void buttonsay() override { qDebug() << "MacButton"; }
};

class WinButton : public Button 
{
public:
	void buttonsay() override { qDebug() << "WinButton"; }
};
