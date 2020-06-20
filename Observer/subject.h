#pragma once
#include <QList>

class Observer;

class Subject
{
public:
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObservers() = 0;
};

class WeatherData : public Subject
{
public:
	void registerObserver(Observer* o) override;
	void removeObserver(Observer* o) override;
	void notifyObservers() override;
	void measurementsChanged();
	void setMeasurements(float temperature, float humidity, float pressure);

private:
	QList<Observer*> observers;
	float temperature;
	float humidity;
	float pressure;
};
