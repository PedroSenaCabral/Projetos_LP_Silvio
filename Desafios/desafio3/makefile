# Arquivo de Script MakeFile
# Desafio 3 apresentado na aula de LP01 do dia 22/11/2018
# Repositório de origem disponível em https://github.com/igorbrunoo/DesafioLP.git
#
# $@ = nome da regra de compilação
# $^ = lista de depedências da regra
# $< = primeira dependência da regra

# comando de compilação do G++
CC = g++

# diretórios usados
INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin

# nome do executáveL
PROG = $(BIN)/main

# flags de compilação
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

OBJTS = $(OBJ)/main.o

all: mkdirs $(PROG)

mkdirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

$(PROG): $(OBJTS)
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

debug: $(PROG)
	gdb $(PROG)

run:
	$(PROG)

# propriedades para serem usadas ao compilar no windows com o MinGW com gcc e gdb
# não usar o comando Make e sim o executável: mingw32-make.exe

mkdirswin:
	if not exist $(BIN) mkdir "$(BIN)
	if not exist $(OBJ) mkdir "$(OBJ)

runwin: mkdirswin $(PROG)
	chcp 65001
	$(PROG)

cleanwin: 
	del /q "$(BIN)\*
	del /q "$(OBJ)\*
