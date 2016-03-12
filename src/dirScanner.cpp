#include "dirScanner.h"
#include <iostream>

std::map<std::string, std::string> DirScanner::getOriginalNifs(){
	return this->originalNifs;
}

bool DirScanner::scan(std::string dirToScanName)
{
	boost::filesystem::path dirToScan(dirToScanName);

	if(!this->canBeScanned(dirToScan)){
		return false;
	}

	return innerScan(dirToScan);

	return true;
}

bool DirScanner::canBeScanned(boost::filesystem::path dirToScan)
{
    if(!boost::filesystem::exists(dirToScan)){
    	return false;
    }
    if(!boost::filesystem::is_directory(dirToScan)){
    	return false;
    }
    return true;
}

bool DirScanner::innerScan(boost::filesystem::path dirToScan)
{
	boost::filesystem::directory_iterator dirIter(dirToScan);

	std::string fileNameStem = "";
	std::string floraNifFileStem = "";
	std::string filePath = "";
	std::string ext = "";
	std::string floraString = "flora_";
	unsigned long int floraStringLength = floraString.length();

	while(dirIter != boost::filesystem::directory_iterator())
	{
		boost::filesystem::path currentPath = dirIter->path();
		std::cout << currentPath.string() << std::endl;
		if(canBeScanned(currentPath)){
			innerScan(currentPath);
		}
		ext = currentPath.extension().string();
		fileNameStem = currentPath.stem().string();
		filePath = currentPath.string();
		++dirIter;

		if(!boost::iequals(ext,".nif")){
			continue;
		}

		if(fileNameStem.length() <= floraString.length())
		{
			continue;
		}

		std::string tempFlora = fileNameStem.substr(0, floraStringLength);
		if(!boost::iequals(tempFlora, floraString)){
			continue;
		}

		floraNifFileStem = fileNameStem.erase(0,floraStringLength);
		originalNifs[floraNifFileStem]=filePath;

	}

	return true;
}
