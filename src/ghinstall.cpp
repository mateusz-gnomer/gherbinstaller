#include <iostream>
#include <string>

#include "./dirScanner.hpp"
#include "./FileMover.hpp"
#include "./logger.hpp"



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

    Logger log();

    DirScanner scanner();
    scanner.attachLogger(log);
    scanner.scan(dataDir);

    DirAnalyzer analyzer();
    analyzer.setOriginals(scanner.getOriginalNifs());
    analyzer.setPicked(scanner.getPickedNifs());
    analyzer.setUnpicked(scanner.getUnpickedNifs());
    analyzer.setEmpty(emptyNif);
    analyzer.analyze();

    FileMover mover();
    mover.attachLogger(logger);
    mover.move(analyzer.getFilesToMove());
    mover.copy(analyzer.getFilesToCopy());

    logger.printLog();
    return 0;
}
