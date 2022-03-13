CFLAGS=-g -Wall -pedantic
LDFLAGS=

.PHONY: all
all: maximum-resident

maximum-resident: maximum-resident.o
	$(CC) $(LDFLAGS) -o $(.TARGET) $(.ALLSRC)

.c.o:
	$(CC) $(CFLAGS) -c -o $(.TARGET) $(.IMPSRC)

clean: .PHONY
	rm -f *.o maximum-resident
