CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/matrix.h $(INC)/segtree.h
OBJS = $(OBJ)/main.o $(OBJ)/segtree.o
CFLAGS = -Wall -g -c -I$(INC) -std=c++11
EXE = $(BIN)/tp3.out

all: run

run: $(EXE)
	$(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -g -o $(EXE) $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
