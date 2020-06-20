#pragma once

class Subject;

class DisplayElement
{
public:
	virtual void display() = 0;
};


class Observer
{
public:
	virtual void update(float temp, float humidity, float pressure) = 0;
};

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
public:
	CurrentConditionsDisplay(Subject* weatherData);
	void update(float temp, float humidity, float pressure) override;
	void display() override;

private:
	float temperature;
	float humidity;
	Subject* weatherData;
};
