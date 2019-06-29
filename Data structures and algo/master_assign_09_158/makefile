# Makefile for executable adjust

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -pedantic -Wall -g

# ****************************************************
# Entries to bring the executable up to date

output: 158-assign09.o definitions.o
	$(CC) $(CFLAGS) -o output 158-assign09.o definitions.o

158-assign09.o: 158-assign09.c heading.h
	$(CC) $(CFLAGS) -c 158-assign09.c

definitions.o: definitions.c heading.h
	$(CC) $(CFLAGS) -c definitions.c

clean:
	rm -f *.o
