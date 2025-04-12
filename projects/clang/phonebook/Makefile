CC = gcc
CFLAGS = -Wall -std=c99
SRC = main.c
TARGET = a.out

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
