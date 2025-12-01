CC = gcc
CFLAGS = -Wall

program: main.o utils.o
    $(CC) -o program main.o utils.o

main.o: main.c
    $(CC) $(CFLAGS) -c main.c

utils.o: utils.c
    $(CC) $(CFLAGS) -c utils.c
