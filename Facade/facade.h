#pragma once
#include "shape.h"

class ShapeMaker
{
private:
    Shape* circle;
    Shape* rectangle;
    Shape* square;

public:
    ShapeMaker()
    {
        circle = new Circle();
        rectangle = new Rectangle();
        square = new Square();
    }

    void drawCircle() {
        circle->draw();
    }
    void drawRectangle() {
        rectangle->draw();
    }
    void drawSquare() {
        square->draw();
    }
};