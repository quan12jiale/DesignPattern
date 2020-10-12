#pragma once
#include <string>

class ImageImp;

//抽象图像类：抽象类  
class Image
{
protected:
    ImageImp* imp;

public:
    void setImageImp(ImageImp* imp) 
    {
        this->imp = imp;
    }

    virtual void parseFile(std::string fileName) = 0;
};
