CPP=g++
CC=gcc
OBJ= main.o
LINKOBJ= main.o
BIN=decorator
CXXFLAGS= -g3 -std=c++11
LIBS= -L -static-libgcc -g3 -pthread
RM=rm -rf
.PHONY: all clean
all: $(BIN)
clean:
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)
