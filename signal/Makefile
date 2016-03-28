TARGET=test-signal.out
CC=gcc
SRC=signal

$(TARGET): $(SRC).o
	$(CC) $(CFLAGS) -o $@  $^
	size $@

.o:.c


test.pid:
	./$(TARGET) & echo $$! > $@
	
test: test.pid
	@echo `cat $<`
	@kill -USR1 `cat $<`
	@kill -USR2 `cat $<`
	@kill `cat $<`
	@rm -rf $<
	
clean:
	rm -rf *.out *.o
