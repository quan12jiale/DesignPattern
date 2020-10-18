#pragma once
#include <QString>

class AbstractLogger 
{
public:
    enum LoggerLevel { 
        INFO , 
        DEBUG,
        ERROR
    };

protected:
    LoggerLevel level;

    //责任链中的下一个元素
    AbstractLogger* nextLogger;

public:
    void setNextLogger(AbstractLogger* nextLogger) {
        this->nextLogger = nextLogger;
    }

    void logMessage(LoggerLevel level, QString message) {
        if (this->level == level) {
            write(message);
        }
        else if (nextLogger != nullptr) {
            nextLogger->logMessage(level, message);
        }
    }

    virtual void write(QString message) = 0;
};
