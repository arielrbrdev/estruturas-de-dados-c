# Makefile para Questão 1

CC = gcc
CFLAGS = -Wall -O2
OBJS = busca.c estatisticas.c resolveq1.c vetor.c
DEPS = programa.h

all: mainq1

mainq1: $(OBJS)
	$(CC) $(CFLAGS) -o mainq1 $(OBJS) -lm

clean:
	rm -f mainq1 *.o

.PHONY: all clean
