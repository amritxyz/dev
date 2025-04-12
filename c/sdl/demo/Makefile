# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2 `pkg-config --cflags sdl2`
LDFLAGS = `pkg-config --libs sdl2` -lm

# Target binary name
TARGET = main

# Source files
SRC = main.c

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Clean build artifacts
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
