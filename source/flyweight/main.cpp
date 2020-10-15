#include "StringPool.h"
#include <QDebug>

int main()
{
    StringPool* oStringPool = StringPool::getSingleInstance();
    oStringPool->init();

    oStringPool->addStrProp("ZhangSan");
    oStringPool->addStrProp("LiSi");
    oStringPool->addStrProp("WangWu");
    oStringPool->addStrProp("ZhangSan");
    oStringPool->addStrProp("LiSi");
    oStringPool->addStrProp("WangWu");

    int nPropCount = oStringPool->getPropCount();
    qDebug() << QString::fromStdWString(L"×Ö·û´®¸öÊý :") << nPropCount;
    for (int i = 0; i < nPropCount; i++)
    {
        qDebug() << oStringPool->getStrPropByIndex(i);
    }
}