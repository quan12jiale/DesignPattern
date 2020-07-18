#include "PrinterProxy.h"

// https://github.com/jaredtao/DesignPattern/tree/master/code/Struct/Proxy
int main(int argc, char *argv[])
{
    Printable* p = new PrinterProxy("123");
    std::cout << p->getPrinterName() << std::endl;

    p->setPrinterName("456");
    std::cout << p->getPrinterName() << std::endl;

    p->print();
    p->setPrinterName("789");
    p->print();
    delete p;
    return 0;
}
