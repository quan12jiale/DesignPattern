#include "director.h"
#include <QDebug>

int main()
{
    ComputerDirector* director = new ComputerDirector();//1
    ComputerBuilder* builder = new MacComputerBuilder("I5������", "����125");//2
    director->makeComputer(builder);//3
    Computer* macComputer = builder->getComputer();//4

    ComputerBuilder* lenovoBuilder = new LenovoComputerBuilder("I7������", "����ʿ222");
    director->makeComputer(lenovoBuilder);
    Computer* lenovoComputer = lenovoBuilder->getComputer();
    qDebug() << "build success";
}