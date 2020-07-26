# -*- MakeFile -*-
# Usage:
# make          # compile all binary
# make clean    # remove ALL binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: ${BINS}

%: %.c
	@echo "Building.."
	${CC} $(CFLAGS) $< -o $@

clean:
	@echo "Cleaning up..."
	@-rm -v ${BINS}
