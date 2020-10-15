#include "StringPool.h"

StringPool* StringPool::m_pInstance = nullptr;
QMutex StringPool::m_lockMutex;

const int g_nDefaultMaxSize = 65535;

StringPool::StringPool()
{
}

StringPool::~StringPool()
{
    m_Vector.clear();
    m_Vector.swap(std::vector<QString>());
}

StringPool* StringPool::getSingleInstance()
{
    if (nullptr == m_pInstance)
    {
        QMutexLocker oLocker(&m_lockMutex);
        {
            if (nullptr == m_pInstance)
            {
                m_pInstance = new StringPool();
            }
        }
    }
    return m_pInstance;
}

void StringPool::freeInstance()
{
    if (nullptr != m_pInstance)
    {
        QMutexLocker oLocker(&m_lockMutex);
        {
            if (nullptr != m_pInstance)
            {
                delete m_pInstance;
                m_pInstance = nullptr;
            }
        }
    }
}

QString& StringPool::getStrPropByIndex(int nIndex)
{
    if (nIndex < 0)
    {
        nIndex = 0;
    }
    return m_Vector[nIndex];
}

int StringPool::addStrProp(const QString& strProp)
{
    if (m_PropHash.contains(strProp))
    {
        return m_PropHash[strProp];
    }

    m_Vector.push_back(strProp);
    int nIndex = m_Vector.size() - 1;
    m_PropHash[strProp] = nIndex;
    return  nIndex;
}

int StringPool::getPropCount()
{
    return m_Vector.size();
}

void StringPool::init()
{
    m_Vector.reserve(g_nDefaultMaxSize);
    m_Vector.push_back(QString(""));
    m_Vector.push_back(QString("null"));

    m_PropHash.insert(QString(""), 0);
    m_PropHash.insert(QString("null"), 1);
}

void StringPool::clearHashMap()
{
    m_PropHash.clear();

    m_PropHash.swap(QHash<QString, int>());
}
