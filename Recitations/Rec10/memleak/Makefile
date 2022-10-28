CC=gcc --std=c99 -g

all: memleak

segf: memleak.c
	$(CC) memleak.c -o memleak

clean:
	rm -f *.o memleak
