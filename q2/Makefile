# Makefile para Questão 2

CC = gcc
CFLAGS = -Wall -O2
OBJS = busca_sequencial.c mainpr.c
DEPS = TADlista.h

all: mainq2

mainq2: $(OBJS)
	$(CC) $(CFLAGS) -o mainq2 $(OBJS) -lm

clean:
	rm -f mainq2 *.o

.PHONY: all clean
