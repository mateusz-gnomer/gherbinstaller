#ifndef LOGGABLE
#define LOGGABLE
#include "logger.hpp"


virtual class Loggable{
	virtual void attachLogger(Logger);
	virtual std::string notify();
};

#endif
