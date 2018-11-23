#Questão 12 
#Feito por: Carlos Vinícius dos Santos
#ultima edição 13/11/2018
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build

PROG = $(BIN)/teste
OBJS = $(OBJ)/pessoa.o $(OBJ)/gerente.o $(OBJ)/funcionario.o $(OBJ)/oficina.o $(OBJ)/assistenteTecnico.o $(OBJ)/assistenteAdministrativo.o $(OBJ)/main.o 

all:mkdirs $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/pessoa.o: $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/pessoa.cpp -o $(OBJ)/pessoa.o

$(OBJ)/funcionario.o: $(INC)/funcionario.h $(SRC)/funcionario.cpp $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $(OBJ)/funcionario.o

$(OBJ)/gerente.o: $(INC)/gerente.h $(SRC)/gerente.cpp $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/gerente.cpp -o $(OBJ)/gerente.o

$(OBJ)/assistenteTecnico.o: $(INC)/assistenteTecnico.h $(SRC)/assistenteTecnico.cpp $(INC)/funcionario.h $(SRC)/funcionario.cpp $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/assistenteTecnico.cpp -o $(OBJ)/assistenteTecnico.o

$(OBJ)/assistenteAdministrativo.o: $(INC)/assistenteAdministrativo.h $(SRC)/assistenteAdministrativo.cpp $(INC)/funcionario.h $(SRC)/funcionario.cpp $(INC)/pessoa.h $(SRC)/pessoa.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/assistenteAdministrativo.cpp -o $(OBJ)/assistenteAdministrativo.o	

$(OBJ)/oficina.o: $(INC)/oficina.h $(SRC)/oficina.cpp $(INC)/funcionario.h $(SRC)/funcionario.cpp $(INC)/gerente.h $(SRC)/gerente.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/oficina.cpp -o $(OBJ)/oficina.o

$(OBJ)/main.o:$(INC)/oficina.h $(INC)/gerente.h $(INC)/assistenteTecnico.h $(INC)/assistenteAdministrativo.h $(INC)/pessoa.h $(INC)/funcionario.h $(SRC)/main.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

mkdirs: 
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

run:
	$(BIN)/teste

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*
	