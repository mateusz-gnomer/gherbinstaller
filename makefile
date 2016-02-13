CC=g++
SRC_DIR=src
BIN_DIR=bin
TEST_DIR=test


DIR_SEP=/
TEST_FILE=$(TEST_DIR)$(DIR_SEP)correct.txt
RESULT_FILE=$(TEST_DIR)$(DIR_SEP)result.txt
MAIN_FILE=$(BIN_DIR)$(DIR_SEP)ghinstall

SOURCE_FILES = ghinstall.cpp
SOURCES = $(patsubst %,$(SRC_DIR)$(DIR_SEP)%,$(SOURCE_FILES))

OBJECT_FILES = $(patsubst %.cpp,%.o,$(SOURCE_FILES))
OBJECTS = $(patsubst %,$(BIN_DIR)$(DIR_SEP)%,$(OBJECT_FILES))

all: test

test: $(MAIN_FILE)
	$(BIN_DIR)$(DIR_SEP)ghinstall > $(RESULT_FILE)
	diff $(TEST_FILE) $(RESULT_FILE)
	rm -f $(RESULT_FILE)

$(MAIN_FILE): $(OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -r -f bin/*.*

.PHONY: all test clean
