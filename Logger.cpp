#include "Logger.h"

Logger::Logger(Print* printer, char const* prefix, LoggerLevel level)
{
    this->printer = printer;
    this->prefix = prefix;
    if(strlen(prefix) == 0)
        this->printPre = false;
    else
        this->printPre = true;
    this->filterLevel = level;
}

Logger::~Logger(){}

bool Logger::checkBlocking(LoggerLevel level)
{
    blockPrint = false;
    if(level > filterLevel){
        blockPrint = true;
    }
    return blockPrint;
}

void Logger::printPrefix()
{
    if(printPre)
        print(prefix);
}

void Logger::setPrintPrefix(bool enable)
{
    this->printPre = enable;
}

void Logger::setLevel(LoggerLevel level)
{
    filterLevel = level;
}

void Logger::unlock()
{
    blockPrint = false;
}

Logger& Logger::internPrint(const char* str, LoggerLevel level)
{
    if (checkBlocking(level))
        return *this;
    print(LevelPrefixes[level]);
    printPrefix();
    print(str);
    return *this;
}

Logger& Logger::internPrintln(const char* str, LoggerLevel level)
{
    if (checkBlocking(level))
        return *this;
    print(LevelPrefixes[level]);
    printPrefix();
    println(str);
    return *this;
}

Logger& Logger::none(const char* str)
{
    return internPrint(str, NONE);
}
Logger& Logger::error(const char* str)
{
    return internPrint(str, ERROR);
}
Logger& Logger::warning(const char* str)
{
    return internPrint(str, WARNING);
}
Logger& Logger::info(const char* str)
{
    return internPrint(str, INFO);
}
Logger& Logger::debug(const char* str)
{
    return internPrint(str, DEBUG);
}
Logger& Logger::verbose(const char* str)
{
    return internPrint(str, VERBOSE);
}


Logger& Logger::noneln(const char* str)
{
    return internPrintln(str, NONE);
}
Logger& Logger::errorln(const char* str)
{
    return internPrintln(str, ERROR);
}
Logger& Logger::warningln(const char* str)
{
    return internPrintln(str, WARNING);
}
Logger& Logger::infoln(const char* str)
{
    return internPrintln(str, INFO);
}
Logger& Logger::debugln(const char* str)
{
    return internPrintln(str, DEBUG);
}
Logger& Logger::verboseln(const char* str)
{
    return internPrintln(str, VERBOSE);
}



size_t Logger::write(uint8_t c)
{
    if (blockPrint)
        return 0;
    return printer->write(c);
}
size_t Logger::write(char c)
{
    if (blockPrint)
        return 0;
    return printer->write(c);
}
size_t Logger::write(const char *str)
{
    return write((const uint8_t *) str, strlen(str));
}
size_t Logger::write(const char *buffer, size_t size)
{
    return write((const uint8_t *) buffer, size);
}
size_t Logger::write(const uint8_t *buffer, size_t size)
{
    if (blockPrint)
        return 0;
    if(buffer == NULL)
        return 0;
    return printer->write(buffer, size);
}