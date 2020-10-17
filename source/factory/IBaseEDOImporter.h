#pragma once

class IBaseEDOImporter
{
public:
	virtual bool importElement() = 0;
	virtual bool importEdo() = 0;
};
