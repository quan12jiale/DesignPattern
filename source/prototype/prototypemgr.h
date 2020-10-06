#pragma once
#include "prototype.h"
#include <unordered_map>

class ProductMgr
{
public:
    void loadCache()
    {
        Prototype* prototypeA = new ConcretePrototypeA;
        Prototype* prototypeB = new ConcretePrototypeB;
        Register("prototypeA", prototypeA);
        Register("prototypeB", prototypeB);
    }
    void Register(const std::string& name, Prototype* pro)
    {
        m_map.insert(std::pair<std::string, Prototype*>(name, pro));
    }
    Prototype* getProduct(const std::string& name)
    {
        auto it = m_map.find(name);
        if (it != m_map.end())
        {
            return m_map[name]->clone();
        }
        else
        {
            return nullptr;
        }
    }

private:
    std::unordered_map<std::string, Prototype*> m_map;
};