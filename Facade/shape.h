#pragma once
#include <QDebug>

class Shape
{
public:
	virtual void draw() = 0;
};

class Rectangle : public Shape
{
public:
	void draw()
	{
		qDebug() << "Rectangle::draw()";
	}
};

class Square : public Shape
{
public:
	void draw()
	{
		qDebug() << "Square::draw()";
	}
};

class Circle : public Shape
{
public:
	void draw()
	{
		qDebug() << "Circle::draw()";
	}
};
