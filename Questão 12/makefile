# Makefile for Laboratório 1
# Created by Carlos Vinícius 20/09/2018
# Makefile para executar o segundo exercício do laboratório 1

CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build

PROG = $(BIN)/teste
OBJS = $(OBJ)/pessoa.o $(OBJ)/funcionario.o $(OBJ)/assistenteTecnico.o $(OBJ)/assistenteAdministrativo.o $(OBJ)/supervisor.o $(OBJ)/main.o 

all:mkdirs $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/pessoa.o: $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/pessoa.cpp -o $(OBJ)/pessoa.o

$(OBJ)/funcionario.o: $(INC)/funcionario.h $(SRC)/funcionario.cpp $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $(OBJ)/funcionario.o

$(OBJ)/assistenteTecnico.o: $(INC)/assistenteTecnico.h $(SRC)/assistenteTecnico.cpp $(INC)/funcionario.h $(SRC)/funcionario.cpp $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/assistenteTecnico.cpp -o $(OBJ)/assistenteTecnico.o

$(OBJ)/assistenteAdministrativo.o: $(INC)/assistenteAdministrativo.h $(SRC)/assistenteAdministrativo.cpp $(INC)/funcionario.h $(SRC)/funcionario.cpp $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/assistenteAdministrativo.cpp -o $(OBJ)/assistenteAdministrativo.o	

$(OBJ)/supervisor.o: $(INC)/supervisor.h $(SRC)/supervisor.cpp $(INC)/funcionario.h $(SRC)/funcionario.cpp $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/supervisor.cpp -o $(OBJ)/supervisor.o

$(OBJ)/main.o:$(INC)/assistenteTecnico.h $(INC)/assistenteAdministrativo.h $(INC)/supervisor.h $(INC)/pessoa.h $(INC)/funcionario.h $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

mkdirs: 
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

run:
	$(BIN)/teste

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*
	