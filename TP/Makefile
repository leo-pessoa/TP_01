INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

# Opções do compilador
CC = g++
CFLAGS = -Wall -c -I$(INCLUDE_FOLDER)
LIBS = -lm

# Arquivos
TARGET = $(BIN_FOLDER)/poker
HDR_FILES = $(INCLUDE_FOLDER)/Carta.h $(INCLUDE_FOLDER)/Jogador.h $(INCLUDE_FOLDER)/Mao.h
OBJ_FILES = $(OBJ_FOLDER)/Carta.o $(OBJ_FOLDER)/Jogador.o $(OBJ_FOLDER)/Mao.o $(OBJ_FOLDER)/Main.o

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $(TARGET) $(LIBS) $(OBJ_FILES)

$(OBJ_FOLDER)/Main.o: $(SRC_FOLDER)/Main.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/Main.o $(SRC_FOLDER)/Main.cpp 

$(OBJ_FOLDER)/Carta.o: $(HDR_FILES) $(SRC_FOLDER)/Carta.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/Carta.o $(SRC_FOLDER)/Carta.cpp 

$(OBJ_FOLDER)/Jogador.o: $(HDR_FILES) $(SRC_FOLDER)/Jogador.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/Jogador.o $(SRC_FOLDER)/Jogador.cpp 

$(OBJ_FOLDER)/Mao.o: $(HDR_FILES) $(SRC_FOLDER)/Mao.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/Mao.o $(SRC_FOLDER)/Mao.cpp 

clean:
	rm $(TARGET) $(OBJ_FILES) 