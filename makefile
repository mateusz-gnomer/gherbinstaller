CC=g++
SRC_DIR=src
BIN_DIR=bin
TEST_DIR=test

BOOST_LIBS=-lboost_system -lboost_date_time -lboost_thread -lboost_unit_test_framework


DIR_SEP=/
TEST_FILE=$(TEST_DIR)$(DIR_SEP)target_dir_tree_and_content
TEST_SETUP_SCRIPT=$(TEST_DIR)$(DIR_SEP)create_test_data_dir.sh test/
DIR_SCAN_SCRIPT=$(TEST_DIR)$(DIR_SEP)scan_data.sh $(TEST_DIR)$(DIR_SEP)data
RESULT_FILE=$(TEST_DIR)$(DIR_SEP)result
MAIN_FILE=$(BIN_DIR)$(DIR_SEP)ghinstall
MAIN_ARGS=$(TEST_DIR)$(DIR_SEP)data $(TEST_DIR)$(DIR_SEP)empty.nif

SOURCE_FILES = ghinstall.cpp logger.cpp
SOURCES = $(patsubst %,$(SRC_DIR)$(DIR_SEP)%,$(SOURCE_FILES))

OBJECT_FILES = $(patsubst %.cpp,%.o,$(SOURCE_FILES))
OBJECTS = $(patsubst %,$(BIN_DIR)$(DIR_SEP)%,$(OBJECT_FILES))

all: test

test: $(MAIN_FILE)
	$(TEST_SETUP_SCRIPT)
	$(MAIN_FILE) $(MAIN_ARGS)
	$(DIR_SCAN_SCRIPT) | sort > $(RESULT_FILE)
	diff -i -b $(TEST_FILE) $(RESULT_FILE)
	rm -f $(RESULT_FILE)

#ghinstall is supplied with morrowind data dir and empty nif file
#diff -i ignore case -b ignore whitespaces

loggerTest: $(BIN_DIR)$(DIR_SEP)loggerTest
	$(BIN_DIR)$(DIR_SEP)loggerTest
	
$(BIN_DIR)$(DIR_SEP)loggerTest: $(BIN_DIR)$(DIR_SEP)loggerTest.o $(BIN_DIR)$(DIR_SEP)logger.o
	$(CC) $(LFLAGS) $^ -o $@ $(BOOST_LIBS)
	
$(BIN_DIR)$(DIR_SEP)loggerTest.o: $(TEST_DIR)$(DIR_SEP)loggerTest.cpp
	$(CC) $(CFLAGS) -I.$(DIR_SEP)$(SRC_DIR)$(DIR_SEP) -c $< -o $@
	
$(BIN_DIR)$(DIR_SEP)logger.o: $(SRC_DIR)$(DIR_SEP)logger.cpp
	$(CC) $(CFLAGS) -I.$(DIR_SEP)$(SRC_DIR)$(DIR_SEP) -c $< -o $@

$(MAIN_FILE): $(OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@

#$(OBJECTS): $(SOURCES)
#	$(CC) $(CFLAGS) -c $< -o $@


clean: 
	rm -r -f bin/*.*

.PHONY: all test clean
