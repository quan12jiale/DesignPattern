#include "colleague.h"

int main()
{
    User* robert = new User("Robert");
    User* john = new User("John");

    robert->sendMessage("Hi! John!");
    john->sendMessage("Hello! Robert!");
    return 0;
}