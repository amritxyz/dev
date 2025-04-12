# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2 `pkg-config --cflags sdl2`
LDFLAGS = `pkg-config --libs sdl2` -lm

# Target binary name
TARGET = main

# Source files
SRC = main.c
OBJ = main.o

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile source into object
$(OBJ): main.c main.h
	$(CC) $(CFLAGS) -c main.c

# Clean build artifacts
clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean
