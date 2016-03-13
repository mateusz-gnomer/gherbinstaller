#include "logger.hpp"

void Logger::addToLog(std::string txt){
	this->logText = this->logText + txt;
}

std::string Logger::returnLog(){
	return this->logText;
}
