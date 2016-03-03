#include "dirScanner.h"
#include <iostream>

bool DirScanner::scan(std::string dirToScanName){
	boost::filesystem::path dirToScan(dirToScanName);

	if(!this->checkPath(dirToScan)){
		return false;
	}

	for (boost::filesystem::directory_entry& x : boost::filesystem::directory_iterator(dirToScanName)){
		std::cout << x.path();
	}

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
