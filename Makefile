src = $(wildcard *.c)
obj = $(src:.c=.o)

DEBUG = -g
LDFLAGS = -L . -lc $(DEBUG)
CC = cc
OUTPUT = iNotifyExample

$(OUTPUT): $(obj)
	$(CC) -o $@ $^ $(LDFLAGS) $(DEBUG)

clean:
	rm -f $(obj) $(OUTPOUT)

.PHONY: clean

