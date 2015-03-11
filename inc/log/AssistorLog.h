
/*
 * AssistorLog.h
 *
 *  Created on: Mar 11, 2015
 *      Author: root
 */

#ifndef ASSISTORLOG_H_
#define ASSISTORLOG_H_

#include "log/log.h"
#include <sstream>

using namespace std;

class AssistorLog{
public:
	enum LogType{
		FILE = 0,
		FILE_TS = 1,
		CERR = 2
	};
	static void init_log_system(LogType ltype,
			Log::MessageType clevel,
			const char *filename = NULL,
			ios_base::openmode mode = ios_base::trunc){
		switch(ltype){
		case FILE:
			AssistorLog::logger = new FileLog(filename, clevel, mode);
			break;
		case FILE_TS:
			AssistorLog::logger = new FileLogTS(filename, clevel, mode);
			break;
		default:
			AssistorLog::logger = new CerrLog(clevel);
			break;
		}
	}

	static void finalize_log_system(){
		delete logger;
	}

	static void log(const char *module,
			const Log::MessageType type,
			const char *message){
		logger->log(module, type, message);
	}

	static void log(const char *module,
			const Log::MessageType type,
			const ostringstream &message){
		logger->log(module, type, message.str().c_str());
	}

	static void log(const char *module,
			const Log::MessageType type,
			const string &message){
		logger->log(module, type, message.c_str());
	}
private:
	AssistorLog(){}
	~AssistorLog(){}
	static Log *logger;
};



#endif /* INC_LOG_ASSISTORLOG_H_ */
