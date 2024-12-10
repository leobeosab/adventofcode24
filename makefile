CC	= gcc
CFLAGS = -g
RM = rm -rf

all: build-one

build-ten:
	$(CC) $(CFLAGS) -o bin/10-1 src/10/prog.c src/utilities/*.c
	$(CC) $(CFLAGS) -o bin/10-2 src/10/prog2.c src/utilities/*.c

build-two:
	$(CC) $(CFLAGS) -o bin/2-1 src/2/prog.c src/utilities/*.c
	$(CC) $(CFLAGS) -o bin/2-2 src/2/prog2.c src/utilities/*.c

build-one:
	$(CC) $(CFLAGS) -o bin/1-1 src/1/prog.c src/utilities/*.c
	$(CC) $(CFLAGS) -o bin/1-2 src/1/prog2.c src/utilities/*.c
