CFLAGS=-g -Wall -pedantic
LDFLAGS=

.PHONY: all
all: wheres-the-heap

wheres-the-heap: wheres-the-heap.o
	$(CC) $(LDFLAGS) -o $(.TARGET) $(.ALLSRC)

.c:.o
	$(CC) $(CLFAGS) -c -o $(.TARGET) $(.IMPSRC)

clean: .PHONY
	rm -f *.o wheres-the-heap
