#pragma once
#include <iostream>
#include "implementor.h"

//Windows操作系统实现类：具体实现类  
class WindowsImp : public ImageImp
{
public:
    void doPaint() override 
    {
        //调用Windows系统的绘制函数绘制像素矩阵  
        std::cout << "在Windows操作系统中显示图像：";
    }
};

//Linux操作系统实现类：具体实现类  
class LinuxImp : public ImageImp
{
public:
    void doPaint() override
    {
        //调用Linux系统的绘制函数绘制像素矩阵  
        std::cout << "在Linux操作系统中显示图像：";
    }
};

//Unix操作系统实现类：具体实现类  
class UnixImp : public ImageImp 
{
public:
    void doPaint() override
    {
        //调用Unix系统的绘制函数绘制像素矩阵  
        std::cout << "在Unix操作系统中显示图像：";
    }
};
