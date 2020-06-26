#pragma once
#include <QDebug>

// receiver:�����ߣ�����ִ������Ķ���
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
