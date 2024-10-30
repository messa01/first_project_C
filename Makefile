# nom de compilateur
CC = gcc

#options de compilation
CFLAGS = -Wall -g

#fichiers sources et exécutables
SRCS = main.c db.c
OBJS = $(SRCS:.c=.o)
EXEC = c_program

#règle par défaut (compile tout)
all: $(EXEC)

#comment contruire l'executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

#comment compiler les fichiers.c en fichiers .o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#nettoyage des fichiers objets et de l'executable
clean:
	rm -f $(OBJS) $(EXEC)
