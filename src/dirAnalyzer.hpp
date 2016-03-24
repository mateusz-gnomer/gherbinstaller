#ifndef DIRANALYZER
#define DIRANALYZER

#include <map>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

#include "loggable.hpp"
//#include <string>

class DirAnalyzer{
	private:
		Logger *logger;
		void notify(std::string str);

		std::vector<std::pair<std::string, std::string>> filesToMove;
		std::vector<std::pair<std::string, std::string>> filesToCopy;

		const std::map<std::string, std::string> originalNifs;
		const std::map<std::string, std::string> pickedNifs;
		const std::map<std::string, std::string> unpickedNifs;
		const std::string emptyNif;

		void findPicked(std::pair<std::string, std::string>);
	public:
		DirAnalyzer(std::map<std::string, std::string>,
				std::map<std::string, std::string>,
				std::map<std::string, std::string>,
				std::string,
				Logger *logger);

		void analyze();

		std::vector<std::pair<std::string, std::string>> getFilesToMove();
		std::vector<std::pair<std::string, std::string>> getFilesToCopy();

		virtual ~DirAnalyzer(){}

};


#endif
