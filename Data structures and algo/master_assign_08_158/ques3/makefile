# Makefile for executable adjust

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -pedantic -Wall -g

# ****************************************************
# Entries to bring the executable up to date

output: main.o definitions.o
	$(CC) $(CFLAGS) -o output main.o definitions.o

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

definitions.o: definitions.c header.h
	$(CC) $(CFLAGS) -c definitions.c

clean:
	rm -f *.o
