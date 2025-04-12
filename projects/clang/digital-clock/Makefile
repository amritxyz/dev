CC = gcc
CFLAGS = -Wall -std=c99
NCURSES_FLAGS = -lncurses  # ncurses library

SRC = main.c

TARGET = a.out

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(NCURSES_FLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean ncurses basic
