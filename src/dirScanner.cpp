#include "dirScanner.h"
#include <iostream>


bool DirScanner::scan(std::string dirToScanName){
	boost::filesystem::path dirToScan(dirToScanName);

	if(!this->checkPath(dirToScan)){
		return false;
	}

	return innerScan(dirToScan);

	return true;
}
std::map<std::string, std::string> DirScanner::getOriginalNifs(){
	return this->originalNifs;
}

bool DirScanner::checkPath(boost::filesystem::path dirToScan){
    if(!boost::filesystem::exists(dirToScan)){
    	return false;
    }
    if(!boost::filesystem::is_directory(dirToScan)){
    	return false;
    }
    return true;
}

bool DirScanner::innerScan(boost::filesystem::path dirToScan){
	boost::filesystem::directory_iterator dirIter(dirToScan);
	while(dirIter != boost::filesystem::directory_iterator()){
		boost::filesystem::path currentPath = dirIter->path();
		std::cout << currentPath.string() << std::endl;
		if(checkPath(currentPath)){
			innerScan(currentPath);
		}

		if(boost::iequals(currentPath.extension().string(),".nif")){
			originalNifs[currentPath.stem().string()]=currentPath.string();
		}
		++dirIter;
	}
	return true;
}
