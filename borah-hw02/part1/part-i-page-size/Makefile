CFLAGS=-g -Wall -pedantic
LDFLAGS=

.PHONY: all
all: page-size

# Instead of $@ and $^ used by GNU make, here we use .TARGET and .ALLSRC,
# which have the same meanings.
page-size: page-size.o
	$(CC) $(LDFLAGS) -o $(.TARGET) $(.ALLSRC)

# Equivalent to the "%.c: %.o" rule in GNU make, which instructs how to build
# a .o file from the corresponding .c file.  The .IMPSRC variable expands to
# the implied source file---ie, the full name of the .c file.
.c.o:
	$(CC) $(CFLAGS) -c -o $(.TARGET) $(.IMPSRC)

# bmake supports an alternative syntax to mark targets as .PHONY (ie, not
# producing an output file, always need to be re-made)
clean: .PHONY
	rm -f *.o page-size
