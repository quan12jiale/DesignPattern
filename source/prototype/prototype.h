#pragma once
#include <iostream>


//Prototypeԭ�ͻ��࣬����Clone�ӿں���
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

    //����clone�ӿڣ����ݲ�ͬ����������ʵ��������
    virtual Prototype* clone() const = 0;
};


//������Prototype��ʵ����ӿں���
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
    //�������캯��
    ConcretePrototypeA(const ConcretePrototypeA&)
    {
        std::cout << "ConcretePrototypeA::ConcretePrototypeA(const ConcretePrototypeA&)" << std::endl;
    }
    //ʵ�ֻ��ඨ���Clone�ӿڣ��ڲ����ÿ������캯��ʵ�ָ��ƹ���
    virtual ConcretePrototypeA* clone() const
    {
        return new ConcretePrototypeA(*this);
    }
};


//������Prototype��ʵ����ӿں���
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
    //�������캯��
    ConcretePrototypeB(const ConcretePrototypeB&)
    {
        std::cout << "ConcretePrototypeB::ConcretePrototypeB(const ConcretePrototypeB&)" << std::endl;
    }
    //ʵ�ֻ��ඨ���Clone�ӿڣ��ڲ����ÿ������캯��ʵ�ָ��ƹ���
    virtual ConcretePrototypeB* clone() const
    {
        return new ConcretePrototypeB(*this);
    }
};