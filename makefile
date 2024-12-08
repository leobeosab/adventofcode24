CC	= gcc
CFLAGS = -g
RM = rm -rf

build:
	$(CC) $(CFLAGS) -o bin/1-1 src/1/prog.c src/utilities/*.c
	$(CC) $(CFLAGS) -o bin/1-2 src/1/prog2.c src/utilities/*.c
