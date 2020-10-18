#pragma once
#include <QDebug>
#include "handler.h"

class InfoLogger : public AbstractLogger
{
public:
    InfoLogger(LoggerLevel level) {
        this->level = level;
    }

    void write(QString message) override
    {
        qDebug() << ("Info::Logger: " + message);
    }
};

class DebugLogger : public AbstractLogger
{
public:
    DebugLogger(LoggerLevel level) {
        this->level = level;
    }

    void write(QString message) override
    {
        qDebug() << ("Debug::Logger: " + message);
    }
};

class ErrorLogger : public AbstractLogger 
{
public:
    ErrorLogger(LoggerLevel level) {
        this->level = level;
    }

    void write(QString message) override 
    {
        qDebug() << ("Error::Logger: " + message);
    }
};
