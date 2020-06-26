#pragma once
#include "target.h"
#include "adaptee.h"

class TurkeyAdapter : public Duck
{
private:
	Turkey* turkey;
public:
	TurkeyAdapter(Turkey* turkey)
	{
		this->turkey = turkey;
	}

	void quack() override { turkey->gobble(); }
	void fly() override
	{
		for (size_t i = 0; i < 5; i++)
		{
			turkey->fly();
		}
	}
};
