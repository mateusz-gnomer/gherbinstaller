#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include "../src/logger.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(logger)
{
	Logger l;
	l.addToLog("lol");
	BOOST_CHECK(l.returnLog()=="lol");
	l.addToLog("lol");
	BOOST_CHECK(l.returnLog()=="lollol");
	l.addToLog("\nlol");
	BOOST_CHECK(l.returnLog()=="lollol\nlol");
}

