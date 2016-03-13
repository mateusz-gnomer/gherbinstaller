#include "dirScanner.hpp"

#include <iostream>

std::map<std::string, std::string> DirScanner::getOriginalNifs(){
	return this->originalNifs;
}

std::map<std::string, std::string> DirScanner::getPickedNifs(){
	return this->pickedNifs;
}

std::map<std::string, std::string> DirScanner::getUnpickedNifs(){
	return this->unpickedNifs;
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
	std::string pickedNifFileStem = "";
	std::string unpickedNifFileStem = "";
	std::string filePath = "";
	std::string ext = "";
	std::string floraString = "flora_";
	unsigned long int floraStringLength = floraString.length();
	unsigned long int fileNameStemLength = 0;

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
		fileNameStemLength = fileNameStem.length();

		++dirIter;

		if(!boost::iequals(ext,".nif")){
			continue;
		}

		if(fileNameStem[fileNameStem.length()-1]=='P'&&
				fileNameStem[fileNameStem.length()-2]=='_'&&
				filePath.find("GHerb") != std::string::npos)
		{
			pickedNifFileStem = fileNameStem.substr(0,fileNameStemLength-2);
			pickedNifs[pickedNifFileStem]=filePath;
			continue;

		}

		if(fileNameStem[fileNameStem.length()-1]=='U'&&
				fileNameStem[fileNameStem.length()-2]=='_'&&
				filePath.find("GHerb") != std::string::npos)
		{
			unpickedNifFileStem = fileNameStem.substr(0,fileNameStemLength-2);
			unpickedNifs[unpickedNifFileStem]=filePath;
			continue;

		}

		if(fileNameStem.length() >= floraString.length())
		{
			std::string tempFlora = fileNameStem.substr(0, floraStringLength);

			if(boost::iequals(tempFlora, floraString) &&
					filePath.find("GHerb") == std::string::npos)
			{
				floraNifFileStem = fileNameStem.erase(0,floraStringLength);
				originalNifs[floraNifFileStem]=filePath;
				continue;
			}

		}
	}

	return true;
}
