TARGET = tree
SRC = tree.c
CFLAGS = -Wall -std=c99 

CC = gcc
GDB = gdb

all: $(TARGET).out

$(TARGET).out: $(SRC)
	$(CC) $^ $(CFLAGS) -o $@

$(TARGET)_debug: $(SRC)
	$(CC) $^ $(CFLAGS) -g3 -DDEBUG -o $@.out
	$(GDB) -q $@.out

clean:
	rm -rf *.out
