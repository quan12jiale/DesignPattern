#pragma once
#include "receiver.h"

class Command
{
public:
	virtual void execute() = 0;
    virtual void undo() = 0;
};

class BuyCommand : public Command
{
private:
    Receiver* receiver;

public:
    BuyCommand(Receiver* receiver)
    {
        this->receiver = receiver;
    }

    void execute() override
    {
        receiver->buy();
    }
    void undo() override
    {
        receiver->sell();
    }
};

class SellCommand : public Command
{
private:
    Receiver* receiver;

public:
    SellCommand(Receiver* receiver)
    {
        this->receiver = receiver;
    }

    void execute() override
    {
        receiver->sell();
    }
    void undo() override
    {
        receiver->buy();
    }
};
