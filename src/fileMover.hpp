#ifndef FILEMOVER
#define FILEMOVER

#include "loggable.hpp"

class FileMover: public Loggable{
	public:
		void move(std::vector<std::pair<std::string, std::string>>);
		void copy(std::vector<std::pair<std::string, std::string>>);
};

#endif
