#include "product.h"

class ComputerBuilder
{
public:
    virtual void setUsbCount() = 0;
    virtual void setKeyboard() = 0;
    virtual void setDisplay() = 0;

    virtual Computer* getComputer() = 0;
};


class MacComputerBuilder : public ComputerBuilder
{
private:
    Computer* computer;
public:
    MacComputerBuilder(QString cpu, QString ram) {
        computer = new Computer(cpu, ram);
    }
    void setUsbCount() override {
        computer->setUsbCount(2);
    }
    void setKeyboard() override {
        computer->setKeyboard("ƻ������");
    }
    void setDisplay() override {
        computer->setDisplay("ƻ����ʾ��");
    }
    Computer* getComputer() override {
        return computer;
    }
};


class LenovoComputerBuilder : public ComputerBuilder
{
private:
    Computer* computer;
public:
    LenovoComputerBuilder(QString cpu, QString ram) {
        computer = new Computer(cpu, ram);
    }
    void setUsbCount() override {
        computer->setUsbCount(4);
    }
    void setKeyboard() override {
        computer->setKeyboard("�������");
    }
    void setDisplay() override {
        computer->setDisplay("������ʾ��");
    }
    Computer* getComputer() override {
        return computer;
    }
};