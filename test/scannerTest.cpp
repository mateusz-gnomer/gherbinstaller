
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE scannerTest
#include "../src/dirScanner.hpp"
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


BOOST_AUTO_TEST_CASE(scanningOriginals)
{
	DirScanner s;
	s.scan("./test/data");
	BOOST_CHECK(s.getOriginalNifs()["no_picked"]=="./test/data/Meshes/FLORA_no_picked.nif");
}

BOOST_AUTO_TEST_CASE(countingOriginals)
{
	DirScanner s;
	s.scan("./test/data");
	BOOST_CHECK(s.getOriginalNifs().size()==6); //6

}

BOOST_AUTO_TEST_CASE(scanningPicked)
{
	DirScanner s;
	s.scan("./test/data");
	BOOST_CHECK(s.getPickedNifs()["Black_Anther_01"]
								  =="./test/data/Meshes/GHerb/Black_Anther_01_P.nif");

}

BOOST_AUTO_TEST_CASE(countingPicked)
{
	DirScanner s;
	s.scan("./test/data");
	BOOST_CHECK(s.getPickedNifs().size()==5); //5
}

BOOST_AUTO_TEST_CASE(scanningUnpicked)
{
	DirScanner s;
	s.scan("./test/data");
	BOOST_CHECK(s.getUnpickedNifs()["mock"]
								  =="./test/data/Meshes/GHerb/mock_U.nif");

}

BOOST_AUTO_TEST_CASE(countingUnpicked)
{
	DirScanner s;
	s.scan("./test/data");
	BOOST_CHECK(s.getUnpickedNifs().size()==1); //1
}

