/*
 * log.h
 *
 *  Created on: Mar 11, 2015
 *      Author: root
 */

#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <fstream>
#include <stdlib.h>		// added by like.ma for rolling log file

using namespace std;

/**
 *  The Logger class is an interface used by OpenNebula components to log
 *  messages
 */
class Log
{
public:
    enum MessageType {
        ERROR   = 0,
        WARNING = 1,
        INFO    = 2,
        DEBUG   = 3,
        DDEBUG  = 4,
        DDDEBUG = 5
    };

    static const char error_names[];

    Log(const MessageType _level = WARNING):log_level(_level){};

    virtual ~Log(){};

    // -------------------------------------------------------------------------
    // Logger interface
    // -------------------------------------------------------------------------

    virtual void log(
        const char *            module,
        const MessageType       type,
        const char *            message) = 0;

protected:
    /**
     *  Minimum log level for the messages
     */
    MessageType log_level;
};

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/**
 *  Log messages to a log file
 */
class FileLog : public Log
{
public:
    FileLog(const string&       file_name,
            const MessageType   level    = WARNING,
            ios_base::openmode  mode     = ios_base::app);

    virtual ~FileLog();

    virtual void log(
        const char *            module,
        const MessageType       type,
        const char *            message);

private:
    char * log_file;
};

/**
 *  Log messages to a log file
 */
class FileLogTS : public FileLog
{
public:
    FileLogTS(const string&       file_name,
                    const MessageType   level    = WARNING,
                    ios_base::openmode  mode     = ios_base::app)
                       :FileLog(file_name,level,mode)
    {
        pthread_mutex_init(&log_mutex,0);
    }

    ~FileLogTS()
    {
        pthread_mutex_destroy(&log_mutex);
    }

    void log(
        const char *            module,
        const MessageType       type,
        const char *            message)
    {
        pthread_mutex_lock(&log_mutex);
        FileLog::log(module,type,message);
        pthread_mutex_unlock(&log_mutex);
    }

private:
    pthread_mutex_t log_mutex;
};


/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/**
 *
 */
class CerrLog : public Log
{
public:
    CerrLog(const MessageType level = WARNING):Log(level){};

    ~CerrLog(){};

    void log(
        const char *            module,
        const MessageType       type,
        const char *            message);
};



#endif /* INC_LOG_LOG_H_ */
