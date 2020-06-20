#include "observer.h"
#include "subject.h"
#include <QDebug>

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject* weatherData)
{
	this->weatherData = weatherData;
	weatherData->registerObserver(this);
}

void CurrentConditionsDisplay::update(float temp, float humidity, float pressure)
{
	this->temperature = temp;
	this->humidity = humidity;
	display();
}

void CurrentConditionsDisplay::display()
{
	qDebug() << "Current conditions:" << temperature << "degrees and" << humidity << "% humidity";
}
