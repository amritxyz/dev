CC      = cc
CFLAGS  = -Wall -Werror -Wextra -std=c99
LDFLAGS = -lraylib
SRC     = main.c
OBJ     = main.o
OUT     = main

all: $(OUT)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

$(OUT): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -rf *.o main

.PHONY: all dirs run clean
