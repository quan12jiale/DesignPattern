#pragma once
#include <QString>

class User;
class ChatRoom
{
public:
    static void showMessage(User* user, const QString& message);
};