CFLAGS=-g -Wall -pedantic
LDFLAGS=

.PHONY: all
all: swap-this

swap-this: swap-this.o
	$(CC) $(LDFLAGS) -o $(.TARGET) $(.ALLSRC)

.c.o:
	$(CC) $(CFLAGS) -c -o $(.TARGET) $(.IMPSRC)

clean: .PHONY
	rm -f *.o swap-this
