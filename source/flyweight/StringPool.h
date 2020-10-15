#pragma once
#include <vector>
#include <QHash>
#include <QMutex>
#include <QString>

class StringPool
{
private:
    StringPool();
    ~StringPool();

public:
    static StringPool* getSingleInstance();
    static void freeInstance();

public:
    QString& getStrPropByIndex(int nIndex);
    int addStrProp(const QString& strProp);
    int getPropCount();

    void init();
    void clearHashMap();
    
private:
    static StringPool* m_pInstance;
    static QMutex m_lockMutex;

private:
    QHash<QString, int> m_PropHash;
    std::vector<QString> m_Vector;
};
