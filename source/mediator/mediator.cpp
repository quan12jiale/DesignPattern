#include "mediator.h"
#include "colleague.h"
#include <QDateTime>
#include <QDebug>

void ChatRoom::showMessage(User* user, const QString& message)
{
    QString str = QDateTime::currentDateTime().toString();
    str += " [" + user->getName() + "] : " + message;
    qDebug() << str;
}