#include "iterator.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QStringList names;
    names << "Robert" << "John" << "Julie" << "Lora";
    Container* nameRepository = new NameRepository(names);

    Iterator* it = nameRepository->getIterator();
    while (it->hasNext())
    {
        qDebug() << "Name:" << it->next();
    }

    return 0;
}
