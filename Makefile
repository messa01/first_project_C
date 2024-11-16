#variable de compilation
CC = gcc
CFLAGS = -Wall -Wextra -g
#SRCS = main.c db.c
#OBJS = $(SRCS:.c=.o)
#EXEC = c_programm
#cible finale

all: main

main: main.o bd.o
	$(CC) $(CFLAGS) -o main main.o bd.o

main.o: main.c bd.h
	$(CC) $(CFLAGS) -c main.c

bd.o: bd.c bd.h
	$(CC) $(CFLAGS) -c bd.c

clean:
	rm -f *.o main
