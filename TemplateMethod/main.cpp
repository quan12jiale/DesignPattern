#include "template.h"

int main(int argc, char *argv[])
{
    CaffeineBeverageWithHook* coffeeHook = new CoffeeWithHook;
    qDebug() << "Making coffee...";
    coffeeHook->prepareRecipe();

    return 0;
}
