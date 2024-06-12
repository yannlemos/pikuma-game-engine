#include "Logger.h"
#include <iostream>
#include <chrono>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS 1

std::vector<LogEntry> Logger::messages;

std::string CurrentDateTimeToString()
{
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::string output(30, '\0');
	struct tm timeInfo;

	localtime_s(&timeInfo, &now);

	std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", &timeInfo);

	return output;
}

void Logger::Log(const std::string& message)
{	
	LogEntry logEntry;
	logEntry.type = LOG_INFO;
	logEntry.message = "LOG: [" + CurrentDateTimeToString() + "] " + message;

	std::cout << "\x1B[32m" << logEntry.message << "\033[0m" << std::endl;

	messages.push_back(logEntry);
}

void Logger::Err(const std::string& message)
{
	LogEntry logEntry;
	logEntry.type = LOG_ERROR;
	logEntry.message = "ERR: [" + CurrentDateTimeToString() + "] " + message;

	std::cerr << "\x1B[91m" << logEntry.message << "\033[0m" << std::endl;

	messages.push_back(logEntry);
}



