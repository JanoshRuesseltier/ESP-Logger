#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include <Streaming.h>

#if STREAMING_LIBRARY_VERSION < 5
#error Streaming.h is outdated! Version 5 or higher is requered.
#endif

enum LoggerLevel{
    NONE    = 0,
    ERROR   = 1,
    WARNING = 2,
    INFO    = 3,
    DEBUG   = 4,
    VERBOSE = 5
};


class Logger : public Print
{
private:
    Print* printer;
    LoggerLevel filterLevel;
    char const* prefix;
    bool printPre;

    bool blockPrint;

    bool checkBlocking(LoggerLevel level);
    void printPrefix();
    Logger& internPrint(const char* str, LoggerLevel level);

    char const* LevelPrefixes[6] = {
        "",
        "[Error]",
        "[Warning]",
        "[Info]",
        "[Debug]",
        "[Verbose]"
    };

public:

    Logger(Print* printer, char const* prefix = "", LoggerLevel level = INFO);
    ~Logger();

    void setPrintPrefix(bool enable);
    void setLevel(LoggerLevel level);
    void unlock();

    Logger& none(const char* str);
    Logger& error(const char* str);
    Logger& warning(const char* str);
    Logger& info(const char* str);
    Logger& debug(const char* str);
    Logger& verbose(const char* str);

    size_t write(uint8_t);
    size_t write(char);
    size_t write(const char *str);
    size_t write(const char *buffer, size_t size);
    size_t write(const uint8_t *buffer, size_t size);

};

//Get the logger streaming compartible so you can use the << syntax

template<class T>
inline Logger operator << (Logger log, T arg)
{log.print(arg); return log;}

inline Logger operator <<(Logger log, _EndLineCode arg) 
{ log.println(); return log;}

inline Logger &operator <<(Logger &log, const _FLOAT &arg)
{ log.print(arg.val, arg.digits); return log;}

inline Logger &operator <<(Logger &log, const _BASED &arg)
{ log.print(arg.val, arg.base); return log;} 

inline Logger &operator <<(Logger &log, const _BYTE_CODE &arg)
{ log.write(arg.val); return log;} 

#endif