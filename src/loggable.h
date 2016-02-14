#ifndef LOGGABLE
#define LOGGABLE
#include "logger.h"


virtual class Loggable{
	virtual void attach(Logger);
	virtual std::string notify();
};

#endif
