#pragma once
#include <iostream>
#include "abstraction.h"
#include "implementor.h"

//JPG格式图像：扩充抽象类  
class JPGImage : public Image
{
public:
    void parseFile(std::string fileName) override
    {
        //模拟解析JPG文件;
        imp->doPaint();
        std::cout << fileName + "，格式为JPG。\n";
    }
};

//PNG格式图像：扩充抽象类  
class PNGImage : public Image
{
public:
    void parseFile(std::string fileName) override
    {
        //模拟解析PNG文件并获得一个像素矩阵对象m;
        imp->doPaint();
        std::cout << fileName + "，格式为PNG。\n";
    }
};

//BMP格式图像：扩充抽象类  
class BMPImage : public Image
{
public:
    void parseFile(std::string fileName) override
    {
        //模拟解析BMP文件并获得一个像素矩阵对象m;
        imp->doPaint();
        std::cout << fileName + "，格式为BMP。\n";
    }
};

//GIF格式图像：扩充抽象类  
class GIFImage : public Image
{
public:
    void parseFile(std::string fileName) override {
        //模拟解析GIF文件并获得一个像素矩阵对象m;
        imp->doPaint();
        std::cout << fileName + "，格式为GIF。\n";
    }
};
