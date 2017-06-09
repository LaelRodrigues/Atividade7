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

all: init questao01 questao02 questao03 questao04

debug: CFLAGS += -g -O0
debug: all

init:
	@mkdir -p $(OBJ_DIR)/questao01
	@mkdir -p $(OBJ_DIR)/questao02
	@mkdir -p $(OBJ_DIR)/questao03
	@mkdir -p $(OBJ_DIR)/questao04
	@mkdir -p $(BIN_DIR)/

questao01: CFLAGS+= -I$(INC_DIR)/questao01
questao01: $(OBJ_DIR)/questao01/main1.o
	@echo "-----------------"
	@echo "Alvo $@"
	@echo "------------------"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/intervalo $^
	@echo "------------------"
	@echo "+++ [Executavel 'intervalo' criado em $(BIN_DIR)] +++"
	@echo "------------------" 	


$(OBJ_DIR)/questao01/main1.o: $(SRC_DIR)/questao01/main1.cpp $(INC_DIR)/questao01/intervalo.h
	$(CC) -c $(CFLAGS) -o $@ $<

questao02: CFLAGS+= -I$(INC_DIR)/questao02
questao02: $(OBJ_DIR)/questao02/main2.o
	@echo "-----------------"
	@echo "Alvo $@"
	@echo "------------------"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/imprime $^
	@echo "------------------"
	@echo "+++ [Executavel 'imprime' criado em $(BIN_DIR)] +++"
	@echo "------------------" 

$(OBJ_DIR)/questao02/main2.o: $(SRC_DIR)/questao02/main2.cpp $(INC_DIR)/questao02/imprime.h
	$(CC) -c $(CFLAGS) -o $@ $<	


questao03: CFLAGS+= -I$(INC_DIR)/questao03
questao03: $(OBJ_DIR)/questao03/rpn.o $(OBJ_DIR)/questao03/main3.o
	@echo "-----------------"
	@echo "Alvo $@"
	@echo "------------------"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/rpn $^
	@echo "------------------"
	@echo "+++ [Executavel 'rpn' criado em $(BIN_DIR)] +++"
	@echo "------------------" 

$(OBJ_DIR)/questao03/rpn.o: $(SRC_DIR)/questao03/rpn.cpp $(INC_DIR)/questao03/rpn.h
	$(CC) -c $(CFLAGS) -o $@ $<	

$(OBJ_DIR)/questao03/main3.o: $(SRC_DIR)/questao03/main3.cpp
	$(CC) -c $(CFLAGS) -o $@ $<	

questao04: CFLAGS+= -I$(INC_DIR)/questao04
questao04: $(OBJ_DIR)/questao04/main4.o
	@echo "-----------------"
	@echo "Alvo $@"
	@echo "------------------"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/primos $^
	@echo "------------------"
	@echo "+++ [Executavel 'primos' criado em $(BIN_DIR)] +++"
	@echo "------------------" 

$(OBJ_DIR)/questao04/main4.o: $(SRC_DIR)/questao04/main4.cpp $(INC_DIR)/questao04/primos.h
	$(CC) -c $(CFLAGS) -o $@ $<	
	
doxy:
	doxygen -g

doc:
	$(RM) $(DOC_DIR)/*
	doxygen

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*