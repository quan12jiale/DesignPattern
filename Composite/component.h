#pragma once
#include <QString>
#include <QList>
#include <iostream>

// Component ������еĶ��������ӿ�
class MenuComponent
{
public:
	virtual void add(MenuComponent* menuComponent) { throw std::exception(); }
	virtual void remove(MenuComponent* menuComponent) { throw std::exception(); }
	virtual MenuComponent* getChild(int i) { throw std::exception(); }

	virtual QString getName() { throw std::exception(); }
	virtual QString getDescription() { throw std::exception(); }
	virtual double getPrice() { throw std::exception(); }
	virtual bool isVegetarian() { throw std::exception(); }

	virtual void print() { throw std::exception(); }
};

// Leaf ������б�ʾҶ�ӽ�����Ҷ�ӽ��û���ӽ��
class MenuItem : public MenuComponent
{
private:
	QString name;
	QString description;
	bool vegetarian;
	double price;
	
public:
	MenuItem(const QString& name, const QString& description,
		bool vegetarian, double price)
		: name(name),description(description),
		vegetarian(vegetarian),price(price)
	{}

	virtual QString getName() { return name; }
	virtual QString getDescription() { return description; }
	virtual double getPrice() { return price; }
	virtual bool isVegetarian() { return vegetarian; }

	virtual void print() 
	{
		std::cout << " " << getName().toStdString();
		if (isVegetarian())
		{
			std::cout << "(v)";
		}
		std::cout << ", " << getPrice() << std::endl;
		std::cout << "  -- " << getDescription().toStdString() << std::endl;
	}
};

// Composite ������֦�ڵ���Ϊ�������洢�Ӳ���
class Menu : public MenuComponent
{
private:
	QString name;
	QString description;
	QList<MenuComponent*> menuComponents;

public:
	Menu(const QString& name, const QString& description)
		: name(name), description(description){}

	virtual void add(MenuComponent* menuComponent) 
	{ menuComponents.append(menuComponent); }
	virtual void remove(MenuComponent* menuComponent) 
	{ menuComponents.removeOne(menuComponent); }
	virtual MenuComponent* getChild(int i) 
	{ return menuComponents[i]; }

	virtual QString getName() { return name; }
	virtual QString getDescription() { return description; }
	virtual void print()
	{
		std::cout << "\n" << getName().toStdString();
		std::cout << ", " << getDescription().toStdString() << std::endl;
		std::cout << "-----------------------" << std::endl;

		QListIterator<MenuComponent*> iterator(menuComponents);
		while (iterator.hasNext())
		{
			MenuComponent* menuComponent = iterator.next();
			menuComponent->print();
		}
	}
};
