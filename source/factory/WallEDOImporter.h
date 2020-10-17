#pragma once
#include "IBaseEDOImporter.h"
#include <QDebug>

class WallEDOImporter : public IBaseEDOImporter
{
public:
    bool importElement() override;
    bool importEdo() override;
};