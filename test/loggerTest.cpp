#include "../src/logger.h"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>


int main(){

	BOOST_AUTO_TEST_CASE(logger)
	{
		Logger l;
		l.addToLog("lol");
		BOOST_CHECK(l.returnLog()=="lolo");
	}
	return 0;
}
