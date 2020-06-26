#pragma once
#include "command.h"

// invoker:µ÷ÓÃÕß
class Invoker {
private:
    QList<Command*> commandList;
    Command* undoCommand;
    Command* redoCommand;

public:
    Invoker()
    {
        undoCommand = nullptr;
        redoCommand = nullptr;
    }

    void addCommand(Command* command)
    {
        commandList.append(command);
    }

    void runCommand(int index)
    {
        if (index >= 0 && index < commandList.size())
        {
            commandList[index]->execute();
            undoCommand = commandList[index];
        }     
    }

    void runUndoCommand()
    {
        if (undoCommand)
        {
            undoCommand->undo();
            redoCommand = undoCommand;
        }   
    }

    void runRedoCommand()
    {
        if (redoCommand)
        {
            redoCommand->execute();
        }
    }
};