CC=gcc
CFLAGS=-g -Wall
BINS=tries

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -r $(BINS) *dSYM
