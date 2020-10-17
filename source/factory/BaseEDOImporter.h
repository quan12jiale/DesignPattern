#pragma once
#include "IBaseEDOImporter.h"
#include <QDebug>

class BaseEDOImporter : public IBaseEDOImporter
{
public:
    bool importElement() override;
    bool importEdo() override;
};