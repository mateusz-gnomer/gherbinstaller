#ifndef LOGGABLE
#define LOGGABLE
#include "logger.hpp"


class Loggable
{
	public:
		virtual void attachLogger(Logger&) = 0;
};

#endif
