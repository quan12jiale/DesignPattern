#pragma once
#include <iostream>
#include "abstraction.h"
#include "implementor.h"

//JPG��ʽͼ�����������  
class JPGImage : public Image
{
public:
    void parseFile(std::string fileName) override
    {
        //ģ�����JPG�ļ�;
        imp->doPaint();
        std::cout << fileName + "����ʽΪJPG��\n";
    }
};

//PNG��ʽͼ�����������  
class PNGImage : public Image
{
public:
    void parseFile(std::string fileName) override
    {
        //ģ�����PNG�ļ������һ�����ؾ������m;
        imp->doPaint();
        std::cout << fileName + "����ʽΪPNG��\n";
    }
};

//BMP��ʽͼ�����������  
class BMPImage : public Image
{
public:
    void parseFile(std::string fileName) override
    {
        //ģ�����BMP�ļ������һ�����ؾ������m;
        imp->doPaint();
        std::cout << fileName + "����ʽΪBMP��\n";
    }
};

//GIF��ʽͼ�����������  
class GIFImage : public Image
{
public:
    void parseFile(std::string fileName) override {
        //ģ�����GIF�ļ������һ�����ؾ������m;
        imp->doPaint();
        std::cout << fileName + "����ʽΪGIF��\n";
    }
};
