#include "factory.h"

int main(int argc, char *argv[])
{
    FactoryStyle style = FactoryStyle::WIN;

#ifdef FactoryPattern
    Button* btn = Factory::CreateButton(style);
    btn->buttonsay();
#endif // FactoryPattern

#ifdef AbstractFactoryPattern
    AbstractFactory* fac = nullptr;
    switch (style)
    {
    case FactoryStyle::MAC:
        fac = new MacFactory;
        break;
    case FactoryStyle::WIN:
        fac = new WinFactory;
        break;
    }

    Button* button = fac->CreateButton();
    Border* border = fac->CreateBorder();

    button->buttonsay();
    border->bordersay();
#endif // AbstractFactoryPattern

    return 0;
}
