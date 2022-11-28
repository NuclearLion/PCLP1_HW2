CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LIB=-lm

TARGET = my_octave

build: $(TARGET)

my_octave: my_octave.c
	$(CC) $(CFLAGS) $(LIB) my_octave.c matrix_io.c -o my_octave

pack:
	zip -FSr 311CAStaicuDan-Dominic_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGET)

run:
	./my_octave < in.in > out.out

.PHONY: pack clean