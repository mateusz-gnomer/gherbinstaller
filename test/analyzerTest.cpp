
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE scannerTest
#include "../src/dirAnalyzer.hpp"
#include <boost/test/unit_test.hpp>
#include <../src/logger.hpp>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>


BOOST_AUTO_TEST_CASE(analyze)
{
	std::map<std::string, std::string> originalNifs;
	std::map<std::string, std::string> pickedNifs;
	std::map<std::string, std::string> unpickedNifs;
	std::string emptyNifs = "./bogus/empty.nif";

	Logger l;

	originalNifs["kwiatek1"] = "./originals/flora_kwiatek1.nif";
	originalNifs["kwiatek2"] = "./originals/flora_kwiatek2.nif";
	originalNifs["kwiatek3"] = "./originals/Flora_kwiatek3.nif";

	pickedNifs["kwiatek1"] = "./originals/GHerb/kwiatek1_P.nif";
	pickedNifs["kwiatek2"] = "./originals/GHerb/kwiatek2_P.nif";

	unpickedNifs["kwiatek2"] = "./originals/GHerb/kwiatek2_U.nif";

	std::vector<std::pair<std::string, std::string>> goodToCopy;
	std::vector<std::pair<std::string, std::string>> resultToCopy;

	std::vector<std::pair<std::string, std::string>> goodToMove;
	std::vector<std::pair<std::string, std::string>> resultToMove;

	goodToCopy.push_back(std::pair<std::string, std::string>("./originals/GHerb/kwiatek1_P.nif", "./originals/flora_kwiatek1_P.nif"));
	goodToCopy.push_back(std::pair<std::string, std::string>("./originals/GHerb/kwiatek2_P.nif", "./originals/flora_kwiatek2_P.nif"));
	goodToCopy.push_back(std::pair<std::string, std::string>("./bogus/empty.nif", "./originals/flora_kwiatek3_P.nif"));

	//goodToCopy.push_back(std::pair<std::string, std::string>("./originals/GHerb/kwiatek2_U.nif", "./originals/flora_kwiatek2.nif"));

	DirAnalyzer a(originalNifs, pickedNifs, unpickedNifs, emptyNifs, &l);
	a.analyze();
	resultToCopy = a.getFilesToCopy();

	std::sort(goodToCopy.begin(), goodToCopy.end());
	std::sort(resultToCopy.begin(), resultToCopy.end());

	BOOST_CHECK(goodToCopy == resultToCopy);
}

