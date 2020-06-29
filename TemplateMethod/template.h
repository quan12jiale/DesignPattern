#pragma once
#include <QDebug>
#include <iostream>
#include <string>

class CaffeineBeverageWithHook
{
public:
	virtual void prepareRecipe() final
	{
		boilWater();
		brew();
		pourInCup();
		if (customerWantsCondiments())
		{
			addCondiments();
		}
	}

	virtual void brew() = 0;
	virtual void addCondiments() = 0;
	void boilWater() { qDebug() << "Boiling water"; }
	void pourInCup() { qDebug() << "Pouring into cup"; }
	virtual bool customerWantsCondiments() { return true; }
};

class CoffeeWithHook : public CaffeineBeverageWithHook
{
public:
	void brew() override final
	{ 
		qDebug() << "Dripping Coffee through filter";
	}
	void addCondiments() override final
	{
		qDebug() << "Adding Sugar and Milk";
	}

	bool customerWantsCondiments() override final
	{
		std::string answer = getUserInput();
		if (QString::fromStdString(answer).toLower().startsWith('y'))
		{
			return true;
		}
		return false;
	}

private:
	std::string getUserInput()
	{
		std::string answer;
		std::cout << "Would you like milk and sugar with yor coffee (y/n)?" << std::endl;
		std::cin >> answer;

		if (answer.empty())
		{
			answer = "no";
		}
		return answer;
	}
};
