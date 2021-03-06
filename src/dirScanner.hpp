#ifndef DIRSCANNER
#define DIRSCANNER

#include <map>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <algorithm>
#include <iterator>
#include "loggable.hpp"
//#include <string>

class DirScanner: public Loggable{
	Logger *logger;
	std::map<std::string, std::string> originalNifs;
	std::map<std::string, std::string> pickedNifs;
	std::map<std::string, std::string> unpickedNifs;

	bool canBeScanned(boost::filesystem::path dirToScan);
	bool innerScan(boost::filesystem::path dirToScan);
	void notify(std::string str);

public:
	bool scan(std::string dirToScan);

	std::map<std::string, std::string> getOriginalNifs();
	std::map<std::string, std::string> getPickedNifs();
	std::map<std::string, std::string> getUnpickedNifs();
	void attachLogger(Logger *logger);

	virtual ~DirScanner(){}


};


#endif
