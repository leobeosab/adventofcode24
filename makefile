CC	= gcc
CFLAGS = -g
RM = rm -rf

build:
	$(CC) $(CFLAGS) -o bin/1 src/1/prog.c
