#ifndef LOGGER
#define LOGGER
#include <string>

class Logger{
private:
	std::string logText;
public:
	std::string returnLog();
	void addToLog(std::string);
};


#endif
