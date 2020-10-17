#pragma once
#include "IBaseEDOImporter.h"
#include <QDebug>

class BeamEDOImporter : public IBaseEDOImporter
{
public:
    bool importElement() override;
    bool importEdo() override;
};