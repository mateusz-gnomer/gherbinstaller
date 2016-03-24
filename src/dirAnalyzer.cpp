#include "dirAnalyzer.hpp"

DirAnalyzer::DirAnalyzer(const std::map<std::string, std::string> originalNifs,
				const std::map<std::string, std::string> pickedNifs,
				const std::map<std::string, std::string> unpickedNifs,
				const std::string emptyNif,
				Logger *logger):
				originalNifs(originalNifs),
				pickedNifs(pickedNifs),
				unpickedNifs(unpickedNifs),
				emptyNif(emptyNif)
{
	this->logger = logger;
}

void DirAnalyzer::analyze()
{
	std::map<std::string, std::string>::const_iterator iter = originalNifs.begin();
	while(iter!= originalNifs.end()){
		findPicked(*iter);
		++iter;
	}
}

std::vector<std::pair<std::string, std::string>> DirAnalyzer::getFilesToMove()
{
	return this->filesToMove;
}

std::vector<std::pair<std::string, std::string>> DirAnalyzer::getFilesToCopy()
{
	return this->filesToCopy;
}


void DirAnalyzer::notify(std::string str)
{
	this->logger->addToLog(str);
}

void DirAnalyzer::findPicked(std::pair<std::string,std::string> original)
{
	std::string tempOriginalFileLocation = "";
	std::string tempFileDestination = "";
	std::string temp = "";
	temp = original.first;

	std::cout << temp << std::endl;
	if(pickedNifs.find(temp)!=pickedNifs.end())
	{
		std::cout << "Znalazlem " << temp << std::endl;
		tempOriginalFileLocation = pickedNifs.at(temp);
	}
	else
	{
		std::cout << "Nie znalazlem " << temp << std::endl;
		tempOriginalFileLocation = this->emptyNif;
	}
	tempFileDestination = original.second.substr(0,original.second.length()-4) + "_P.nif";
	std::cout << "should copy: " << tempOriginalFileLocation << " to " << tempFileDestination << std::endl;
	filesToCopy.push_back(std::pair<std::string, std::string>(tempOriginalFileLocation,tempFileDestination));
}
