#include <iostream>
#include <string>

#include "dirScanner.hpp"
#include "fileMover.hpp"
#include "dirAnalyzer.hpp"
#include "logger.hpp"



int main(int argc, char *args[]){
    if(argc < 3){
    	std::cout << "Program moves and renames file "
    			"from Graphical Herbalism installation" << std::endl;
    	std::cout << "Usage: prog_name path/to/morrowind/data "
    			"empty_nif_file_path.nif" << std::endl;
    	return 0;
    }

    std::string dataDir = args[1];
    std::string emptyNif = args[2];

    Logger log;

    DirScanner scanner;
    scanner.attachLogger(&log);
    scanner.scan(dataDir);

    DirAnalyzer analyzer(scanner.getOriginalNifs(),
    		scanner.getPickedNifs(),
			scanner.getUnpickedNifs(),
			emptyNif,
			&log);

    analyzer.analyze();

    FileMover mover;
    mover.attachLogger(&log);
    mover.move(analyzer.getFilesToMove());
    mover.copy(analyzer.getFilesToCopy());

    log.returnLog();
    return 0;
}
