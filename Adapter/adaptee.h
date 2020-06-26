#pragma once
#include <QDebug>

// adaptee:±ª  ≈‰’ﬂ
class Turkey
{
public:
	virtual void gobble() = 0;
	virtual void fly() = 0;
};

class WildTurkey : public Turkey
{
public:
	void gobble() override { qDebug() << "Gobble gobble"; }
	void fly() override { qDebug() << "I'm flying a short distance"; }
};
