
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

merge-k-sorted-lists: merge-k-sorted-lists.o
	$(CC) $(CFLAGS) -o merge-k-sorted-lists merge-k-sorted-lists.o

merge-k-sorted-lists.o: merge-k-sorted-lists.cpp
	$(CC) $(CFLAGS) -c merge-k-sorted-lists.cpp

clean:
	rm -rf merge-k-sorted-lists merge-k-sorted-lists.o
