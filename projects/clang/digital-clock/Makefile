CC = gcc
CFLAGS = -Wall -std=c99
NCURSES_FLAGS = -lncurses  # ncurses library

SRC = main.c

LEGACY = main-legacy.c

TARGET = a.out

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(NCURSES_FLAGS)

legacy: $(SRC)
	$(CC) $(LEGACY) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean ncurses basic
