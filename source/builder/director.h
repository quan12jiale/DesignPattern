#pragma once
#include "builder.h"

class ComputerDirector
{
public:
    void makeComputer(ComputerBuilder* builder) {
        builder->setUsbCount();
        builder->setDisplay();
        builder->setKeyboard();
    }
};