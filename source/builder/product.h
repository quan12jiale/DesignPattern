#include <QString>

class Computer
{
private:
    QString cpu;//����
    QString ram;//����
    int usbCount;//��ѡ
    QString keyboard;//��ѡ
    QString display;//��ѡ

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