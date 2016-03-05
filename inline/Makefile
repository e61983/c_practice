CC=gcc
srcs=main.c

all: diff diff_c99

diff: use_inline unuse_inline 
	diff use_inline.s unuse_inline.s 

diff_c99: use_inline_c99 unuse_inline_c99
	diff use_inline_c99.s unuse_inline_c99.s 

unuse_inline: $(srcs)
	$(CC) -O0 -S $< -o $@.s

use_inline:  $(srcs)
	$(CC) -O0 -S -DUSE $< -o $@.s 

unuse_inline_c99: $(srcs)
	$(CC) -O0 -S --std=c99 $< -o $@.s

use_inline_c99:  $(srcs)
	$(CC) -O0 -S -DUSE --std=c99 $< -o $@.s 

clean:
	rm -rf *.s *.out
