#pragma once
#include <QDebug>

// receiver:接收者，真正执行命令的对象。
class Receiver
{
public:
    void buy()
    {
        qDebug() << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] bought";
    }
    void sell()
    {
        qDebug() << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] sold";
    }

private:
    QString name = "ABC";
    int quantity = 10;
};
