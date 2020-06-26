#include "facade.h"

int main(int argc, char *argv[])
{
    ShapeMaker* shapeMaker = new ShapeMaker();

    shapeMaker->drawCircle();
    shapeMaker->drawRectangle();
    shapeMaker->drawSquare();

    return 0;
}
