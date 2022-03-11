CFLAGS=-g -Wall -pedantic
LDFLAGS=

.PHONY: all
all: whither-mmap

whither-mmap: whither-mmap.o
	$(CC) $(LDFLAGS) -o $(.TARGET) $(.ALLSRC)

.c.o:
	$(CC) $(CFLAGS) -c -o $(.TARGET) $(.IMPSRC)

clean: .PHONY
	rm -f *.o whither-mmap
