#include "singleton.h"

int main(int argc, char *argv[])
{
    Singleton* object = Singleton::getInstance();
    object->showMessage();

    return 0;
}
