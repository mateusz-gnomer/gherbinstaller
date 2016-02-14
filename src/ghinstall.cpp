#include <iostream>
#include <string>
#include "logger.h"
#include "dirScanner.h"
#include "FileMover.h"

template <class T>
class PointerWrapper{
private:
	T *p;
public:
	PointerWrapper(T &p){
		this->p = p;
	}
	~PointerWrapper(){
		delete p;
	}
};

int main(int argc, char *args[]){
    if(argc < 3){
    	std::cout << "Program moves and renames file "
    			"from Graphical Herbalism installation" << std::endl;
    	std::cout << "Usage: prog_name path/to/morrowind/data "
    			"empty_nif_file_path.nif" << std::endl;
    	return 0;
    }
    std::string dataDir = new std::string(args[1]);
    std::string emptyNif = new std::string(args[2]);

    Logger log = Logger::getLogger();
    PointerWrapper wrapLogger(log);

    DirScanner *scanner = DirScanner::getDirScanner();
    PointerWrapper wrapScanner(scanner);
    scanner->attachLogger(logger);

    scanner->scan(dataDir);

    FileMover *mover = FileMover::GetFileMover();
    PointerWrapper wrapMover(mover);
    mover->attachLogger(logger);

    mover->move(scanner->getOriginalNifFiles(),
    		    scanner->getPickedNifFiles(),
				scanner->getUnpickedNifFiles(),
				emptyNif);

    logger->printLog();
    return 0;
}
