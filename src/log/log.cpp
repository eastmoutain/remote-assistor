/*
 * log.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: root
 */

#include <log/log.h>
#include <string.h>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <iostream>

const char Log::error_names[] = {'E', 'W', 'I', 'D'};

FileLog::FileLog(const string &file_name,
			const MessageType level,
			ios_base::openmode mode)
		:Log(level),
		 log_file(NULL)
{
	ofstream	file;
	log_file = strdup(file_name.c_str());
	file.open(log_file, mode);

	if(file.fail() == true){
		throw runtime_error("Could not open log file");
	}

	if(file.is_open() == true){
		file.close();
	}
}

FileLog::~FileLog()
{
	if(log_file != NULL){
		free(log_file);
	}
}

void FileLog::log(const char *module,
		const MessageType type,
		const char *message)
{
	char str[26];
	time_t the_time;
	ofstream file;

	if(type <= log_level){
		file.open(log_file, ios_base::app);
		if(file.fail() == true)
			return;

		the_time = time(NULL);
		ctime_r(&the_time, str);
		str[24] = '\0';

		file << str << " ";
		file << '[' << module << ']';
		file << '[' << error_names[type] << ']' << ':';
		file << message << endl;

		file.flush();
		file.close();
	}
}

/*********************************************************************************/
void CerrLog::log(
		const char *module,
		const MessageType type,
		const char *message)
{
	char str[26];
	time_t the_time;
	ofstream file;

	if(type <= log_level){
		the_time = time(NULL);
		ctime_r(&the_time, str);
		str[24] = '\0';

		cerr << str << " ";
		cerr << '[' << module << ']';
		cerr << '[' << error_names[type] << ']' << ':' ;
		cerr << message << endl;

		cerr.flush();
	}
}
