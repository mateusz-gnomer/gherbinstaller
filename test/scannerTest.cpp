#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE scannerTest
#include "../src/dirScanner.h"
#include <boost/test/unit_test.hpp>
#include <map>


BOOST_AUTO_TEST_CASE(dir_exists)
{
	DirScanner s;
	BOOST_CHECK(s.scan("./test")==true);
}

BOOST_AUTO_TEST_CASE(dir_doesnt_exist)
{
	DirScanner s;
	BOOST_CHECK(s.scan("./krowa")==false);
}

BOOST_AUTO_TEST_CASE(dir_is_not_dir)
{
	DirScanner s;
	BOOST_CHECK(s.scan("./test/some_file")==false);
}


BOOST_AUTO_TEST_CASE(scanning)
{
	DirScanner s;
	s.scan("./test/data");
	BOOST_CHECK(s.getOriginalNifs()["no_picked"]=="test/data/Meshes/FLORA_no_picked.nif");
}
