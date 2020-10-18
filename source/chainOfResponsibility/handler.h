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

    //�������е���һ��Ԫ��
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
