SRC = $(wildcard *.cpp)
LIBS=-lmingw32 -lSDL2main -lSDL2
INCLUDES=include
OUTPUT=bin/debug.exe
CC=g++
LIB_DIR=-Llib

build:
	$(CC) $(SRC) -o $(OUTPUT) -I $(INCLUDES) -Llib $(LIBS)

run:$(OUTPUT)
	$(OUTPUT)