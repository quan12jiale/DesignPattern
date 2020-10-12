#pragma once
#include <iostream>
#include "implementor.h"

//Windows����ϵͳʵ���ࣺ����ʵ����  
class WindowsImp : public ImageImp
{
public:
    void doPaint() override 
    {
        //����Windowsϵͳ�Ļ��ƺ����������ؾ���  
        std::cout << "��Windows����ϵͳ����ʾͼ��";
    }
};

//Linux����ϵͳʵ���ࣺ����ʵ����  
class LinuxImp : public ImageImp
{
public:
    void doPaint() override
    {
        //����Linuxϵͳ�Ļ��ƺ����������ؾ���  
        std::cout << "��Linux����ϵͳ����ʾͼ��";
    }
};

//Unix����ϵͳʵ���ࣺ����ʵ����  
class UnixImp : public ImageImp 
{
public:
    void doPaint() override
    {
        //����Unixϵͳ�Ļ��ƺ����������ؾ���  
        std::cout << "��Unix����ϵͳ����ʾͼ��";
    }
};
