#include "dirAnalyzer.hpp"

void DirAnalyzer::setOriginals(std::map<std::string, std::string>)
{

}

void DirAnalyzer::setPicked(std::map<std::string, std::string>)
{

}

void DirAnalyzer::setUnpicked(std::map<std::string, std::string>)
{

}

void DirAnalyzer::setEmpty(std::string)
{

}

void DirAnalyzer::analyze()
{

}

std::vector<std::pair<std::string, std::string>> DirAnalyzer::getFilesToMove()
{
	return this->filesToMove;
}

std::vector<std::pair<std::string, std::string>> DirAnalyzer::getFilesToCopy()
{
	return this->filesToCopy;
}

void DirAnalyzer::attachLogger(Logger *l)
{
	this->logger = l;
}

void DirAnalyzer::notify(std::string str)
{
	this->logger->addToLog(str);
}
