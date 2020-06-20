#include "decorator.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    Beverage* beverage = new Espresso;
    qDebug() << beverage->getDescription() << "$" << beverage->cost();

    Beverage* beverage2 = new DarkRoast;
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    qDebug() << beverage2->getDescription() << "$" << beverage2->cost();

    Beverage* beverage3 = new HouseBlend;
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    qDebug() << beverage3->getDescription() << "$" << beverage3->cost();

    return 0;
}
