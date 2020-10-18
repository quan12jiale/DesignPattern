#include "concreteHandler.h"

AbstractLogger* getChainOfLoggers() 
{
    AbstractLogger* infoleLogger = new InfoLogger(AbstractLogger::INFO);
    AbstractLogger* debugLogger = new DebugLogger(AbstractLogger::DEBUG);
    AbstractLogger* errorLogger = new ErrorLogger(AbstractLogger::ERROR);

    infoleLogger->setNextLogger(debugLogger);
    debugLogger->setNextLogger(errorLogger);

    return infoleLogger;
}

int main()
{
    AbstractLogger* loggerChain = getChainOfLoggers();

    loggerChain->logMessage(AbstractLogger::INFO, 
        "This is an information.");

    loggerChain->logMessage(AbstractLogger::DEBUG,
        "This is a debug level information.");

    loggerChain->logMessage(AbstractLogger::ERROR,
        "This is an error information.");
}
