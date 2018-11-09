CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)
SRC = ./src
INC = ./include
OBJ = ./build
BIN = ./bin

PROG = $(BIN)/teste
OBJS = $(OBJ)/peca.o $(OBJ)/pecaamarela.o $(OBJ)/pecaazul.o $(OBJ)/pecavermelha.o $(OBJ)/fabrica.o $(OBJ)/main.o 

all: mkdirs $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS) 

$(OBJ)/peca.o: $(SRC)/peca.cpp $(INC)/peca.h 
	$(CC) $(CPPFLAGS) -c $(SRC)/peca.cpp -o $(OBJ)/peca.o

$(OBJ)/pecavermelha.o: $(SRC)/pecavermelha.cpp $(INC)/pecavermelha.h $(OBJ)/peca.o 
	$(CC) $(CPPFLAGS) -c $(SRC)/pecavermelha.cpp -o $(OBJ)/pecavermelha.o

$(OBJ)/pecaazul.o: $(SRC)/pecaazul.cpp $(INC)/pecaazul.h $(SRC)/peca.cpp $(INC)/peca.h 
	$(CC) $(CPPFLAGS) -c $(SRC)/pecaazul.cpp -o $(OBJ)/pecaazul.o

$(OBJ)/pecaamarela.o: $(SRC)/pecaamarela.cpp $(INC)/pecaamarela.h $(SRC)/peca.cpp $(INC)/peca.h 
	$(CC) $(CPPFLAGS) -c $(SRC)/pecaamarela.cpp -o $(OBJ)/pecaamarela.o

$(OBJ)/fabrica.o: $(SRC)/fabrica.cpp $(INC)/fabrica.h $(SRC)/peca.cpp $(INC)/peca.h $(SRC)/pecaamarela.cpp $(INC)/pecaamarela.h $(SRC)/pecaazul.cpp $(INC)/pecaazul.h  $(SRC)/pecavermelha.cpp $(INC)/pecavermelha.h 
	$(CC) $(CPPFLAGS) -c $(SRC)/fabrica.cpp -o $(OBJ)/fabrica.o

$(OBJ)/main.o: $(SRC)/main.cpp  $(SRC)/fabrica.cpp $(INC)/fabrica.h $(SRC)/peca.cpp $(INC)/peca.h $(SRC)/pecaamarela.cpp $(INC)/pecaamarela.h $(SRC)/pecaazul.cpp $(INC)/pecaazul.h  $(SRC)/pecavermelha.cpp $(INC)/pecavermelha.h 
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

mkdirs: 
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

run: 
	$(BIN)/teste

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*