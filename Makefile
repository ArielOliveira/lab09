teste = ./bin/teste

BIN_DIR = ./bin
OBJ_DIR = ./build
LIB_DIR = ./lib
INC_DIR = ./include
SRC_DIR = ./src
DOC_DIR = ./doc
TEST_DIR = ./test

CC = g++

CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

OBJS = $(OBJ_DIR)/main.o

.PHONY: dir

$(teste): $(OBJS)
	$(CC) $^ $(CPPFLAGS) -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/arielslib_stack.h $(INC_DIR)/arielslib_list.h
		$(CC) -c $(CPPFLAGS) -o $@ $<

dir:
	mkdir -p bin
	mkdir -p build
	mkdir -p include
	mkdir -p src
	mkdir -p doc
	mkdir -p lib
	mkdir -p test
