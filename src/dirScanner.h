#ifndef DIRSCANNER
#define DIRSCANNER

#include <map>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <algorithm>
#include <iterator>
//#include <string>

class DirScanner{
	std::map<std::string, std::string> originalNifs;

	bool canBeScanned(boost::filesystem::path dirToScan);
	bool innerScan(boost::filesystem::path dirToScan);

public:
	bool scan(std::string dirToScan);

	std::map<std::string, std::string> getOriginalNifs();
};


#endif
