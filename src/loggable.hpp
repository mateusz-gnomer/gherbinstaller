#ifndef LOGGABLE
#define LOGGABLE
#include "logger.hpp"


virtual class Loggable{
	virtual void attach(Logger);
	virtual std::string notify();
};

#endif
