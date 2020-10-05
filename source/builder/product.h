#include <QString>

class Computer
{
private:
    QString cpu;//必须
    QString ram;//必须
    int usbCount;//可选
    QString keyboard;//可选
    QString display;//可选

public:
    Computer(QString cpu, QString ram) {
        this->cpu = cpu;
        this->ram = ram;
    }
    void setUsbCount(int usbCount) {
        this->usbCount = usbCount;
    }
    void setKeyboard(QString keyboard) {
        this->keyboard = keyboard;
    }
    void setDisplay(QString display) {
        this->display = display;
    }
};