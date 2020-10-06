#pragma once
#include <iostream>


//Prototype原型基类，定义Clone接口函数
class Prototype
{
public:
    Prototype()
    {
        std::cout << "Prototype::Prototype()" << std::endl;
    }
    virtual ~Prototype()
    {
        std::cout << "Prototype::~Prototype()" << std::endl;
    }

    //定义clone接口，根据不同的派生类来实例化对象
    virtual Prototype* clone() const = 0;
};


//派生自Prototype，实现其接口函数
class ConcretePrototypeA : public Prototype
{
public:
    ConcretePrototypeA()
    {
        std::cout << "ConcretePrototypeA::ConcretePrototypeA()" << std::endl;
    }
    ~ConcretePrototypeA()
    {
        std::cout << "ConcretePrototypeA::~ConcretePrototypeA()" << std::endl;
    }
    //拷贝构造函数
    ConcretePrototypeA(const ConcretePrototypeA&)
    {
        std::cout << "ConcretePrototypeA::ConcretePrototypeA(const ConcretePrototypeA&)" << std::endl;
    }
    //实现基类定义的Clone接口，内部调用拷贝构造函数实现复制功能
    virtual ConcretePrototypeA* clone() const
    {
        return new ConcretePrototypeA(*this);
    }
};


//派生自Prototype，实现其接口函数
class ConcretePrototypeB : public Prototype
{
public:
    ConcretePrototypeB()
    {
        std::cout << "ConcretePrototypeB::ConcretePrototypeB()" << std::endl;
    }
    ~ConcretePrototypeB()
    {
        std::cout << "ConcretePrototypeB::~ConcretePrototypeB()" << std::endl;
    }
    //拷贝构造函数
    ConcretePrototypeB(const ConcretePrototypeB&)
    {
        std::cout << "ConcretePrototypeB::ConcretePrototypeB(const ConcretePrototypeB&)" << std::endl;
    }
    //实现基类定义的Clone接口，内部调用拷贝构造函数实现复制功能
    virtual ConcretePrototypeB* clone() const
    {
        return new ConcretePrototypeB(*this);
    }
};