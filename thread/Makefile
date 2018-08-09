SOURCE = $(wildcard *.c)
TARGETS = $(patsubst %.c, %, $(SOURCE))

CC = gcc
CFLAGS = -Wall -g
LIB = -lpthread

all:$(TARGETS)

$(TARGETS):%:%.c
		$(CC) $< $(CFLAGS) $(LIB) -o $@

.PHONY:clean all
clean:
	-rm -rf $(TARGETS)
