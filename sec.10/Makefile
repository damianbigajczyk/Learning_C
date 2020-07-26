# -*- MakeFile -*-
# Usage:
# make		# compile all binary
# make clean	# remove ALL binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g
RM = -rm -v *.o ${BIN}

SRC := $(filter-out function.c, $(wildcard *.c))
BIN := $(SRC:%.c=%)

all: function.o ${BIN}

%: %.c
	@echo "Creating object.."
	$(CC) $(CFLAGS) -c $<
	@echo "Linking.."
	$(CC) $(CFLAGS) $@.o function.o -o $@

${BIN}.o: function.c

function.o: function.c function.h
	@echo "Creating object.."
	$(CC) $(CFLAGS) -c function.c

clean:
	@echo "Cleaning up..."
	@$(RM)
