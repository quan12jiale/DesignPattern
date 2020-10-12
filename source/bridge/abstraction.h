#pragma once
#include <string>

class ImageImp;

//����ͼ���ࣺ������  
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
