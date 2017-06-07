RM = rm -rf

CC=g++

LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test


CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: all init clean doxy debug doc 

all: init questao01 questao02

debug: CFLAGS += -g -O0
debug: all

init:
	@mkdir -p $(OBJ_DIR)/questao01
	@mkdir -p $(OBJ_DIR)/questao02
	@mkdir -p $(BIN_DIR)/

questao01: CFLAGS+= -I$(INC_DIR)/questao01
questao01: $(OBJ_DIR)/questao01/main.o
	@echo "-----------------"
	@echo "Alvo $@"
	@echo "------------------"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/intervalo $^
	@echo "------------------"
	@echo "+++ [Executavel 'intervalo' criado em $(BIN_DIR)] +++"
	@echo "------------------" 	


$(OBJ_DIR)/questao01/main.o: $(SRC_DIR)/questao01/main.cpp $(INC_DIR)/questao01/intervalo.h
	$(CC) -c $(CFLAGS) -o $@ $<

questao02: CFLAGS+= -I$(INC_DIR)/questao02
questao02: $(OBJ_DIR)/questao02/main.o
	@echo "-----------------"
	@echo "Alvo $@"
	@echo "------------------"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/imprime $^
	@echo "------------------"
	@echo "+++ [Executavel 'imprime' criado em $(BIN_DIR)] +++"
	@echo "------------------" 

$(OBJ_DIR)/questao02/main.o: $(SRC_DIR)/questao02/main.cpp $(INC_DIR)/questao02/imprime.h
	$(CC) -c $(CFLAGS) -o $@ $<	

doxy:
	doxygen -g

doc:
	$(RM) $(DOC_DIR)/*
	doxygen

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*