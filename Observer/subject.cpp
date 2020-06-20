#include "subject.h"
#include "observer.h"

void WeatherData::registerObserver(Observer* o)
{
	observers.append(o);
}

void WeatherData::removeObserver(Observer* o)
{
	observers.removeOne(o);
}

void WeatherData::notifyObservers()
{
	foreach(Observer * o, observers)
		o->update(temperature, humidity, pressure);
}

void WeatherData::measurementsChanged()
{
	notifyObservers();
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
	measurementsChanged();
}
