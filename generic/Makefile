TARGET = generic

$(CC) = gcc

SRC = main.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -std=c11

all: $(TARGET).out

$(TARGET).out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm $(TARGET).out $(OBJ)

