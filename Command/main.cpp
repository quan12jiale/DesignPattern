#include "invoker.h"

int main(int argc, char *argv[])
{
    Receiver* receiver = new Receiver();

    BuyCommand* buyCommand = new BuyCommand(receiver);
    SellCommand* sellCommand = new SellCommand(receiver);

    Invoker* invoker = new Invoker();
    invoker->addCommand(buyCommand);
    invoker->addCommand(sellCommand);

    invoker->runCommand(0);
    invoker->runUndoCommand();
    invoker->runRedoCommand();

    return 0;
}
