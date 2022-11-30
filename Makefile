#Dan-Dominic Staicu 311CA

CC=gcc
CFLAGS=-Wall -Wextra -std=c99
#LIB=-lm
FILES=my_octave.c matrix_io.c queries.c matirx_mem_op.c array_op.c

TARGET = my_octave

#all:
#	make clean; make build; make run

build: $(TARGET)

my_octave: my_octave.c
	$(CC) $(CFLAGS) $(LIB) $(FILES) -o my_octave

pack:
	zip -FSr 311CAStaicuDan-Dominic_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGET)

run:
	./my_octave < in.in > out.out

.PHONY: pack clean