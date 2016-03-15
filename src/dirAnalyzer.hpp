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
#include "loggable.hpp"
//#include <string>

class DirAnalyzer: public Loggable{
	private:
		Logger *logger;
		void notify(std::string str);

		std::vector<std::pair<std::string, std::string>> filesToMove;
		std::vector<std::pair<std::string, std::string>> filesToCopy;


	public:
		void setOriginals(std::map<std::string, std::string>);
		void setPicked(std::map<std::string, std::string>);
		void setUnpicked(std::map<std::string, std::string>);
		void setEmpty(std::string);
		void analyze();

		std::vector<std::pair<std::string, std::string>> getFilesToMove();
		std::vector<std::pair<std::string, std::string>> getFilesToCopy();
		void attachLogger(Logger&);
		virtual ~DirAnalyzer(){}

};


#endif
