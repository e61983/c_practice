CC = gcc
TARGET = list.out

CFLAGS = -Wall -g3 -pg

SCS = list.o  main.o

ALL: ${TARGET}

$(TARGET): ${SCS}
	$(CC) ${CFLAGS} -o $@ $^

.c.o: $<
	$(CC) ${CFLAGS} -o $@ -c $^

.PHONY: clean

clean:
	rm -rf *.o *.out
