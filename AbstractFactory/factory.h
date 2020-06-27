#pragma once
#include "button.h"
#include "border.h"

#define FactoryPattern
#define AbstractFactoryPattern

enum class FactoryStyle { MAC, WIN };

#ifdef FactoryPattern

class Factory
{
public:
	static Button* CreateButton(FactoryStyle style)
	{
		Button* btn = nullptr;
		switch (style)
		{
		case FactoryStyle::MAC:
			btn = new MacButton;
			break;
		case FactoryStyle::WIN:
			btn = new WinButton;
			break;
		}

		return btn;
	}
};

#endif // FactoryPattern

#ifdef AbstractFactoryPattern

class AbstractFactory
{
public:
	virtual Button* CreateButton() = 0;
	virtual Border* CreateBorder() = 0;
};

class MacFactory : public AbstractFactory
{
public:
	Button* CreateButton() override { return new MacButton; }
	Border* CreateBorder() override { return new MacBorder; }
};

class WinFactory : public AbstractFactory
{
public:
	Button* CreateButton() override { return new WinButton; }
	Border* CreateBorder() override { return new WinBorder; }
};

#endif // AbstractFactoryPattern
