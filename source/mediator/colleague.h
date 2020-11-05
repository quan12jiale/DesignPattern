#pragma once
#include <QString>
#include "mediator.h"

class User
{
public:
    User(const QString& name) { setName(name); }

public:
    QString getName() const { return name; }

    void setName(const QString& name) { this->name = name; }

    void sendMessage(const QString& message) { ChatRoom::showMessage(this, message); }

private:
    QString name;
};