# -*- MakeFile -*-
# Usage:
# make		# compile all binary
# make clean	# remove ALL binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g

SRCS := $(filter-out function.c,$(wildcard *.c))
BINS := $(SRCS:%.c=%)

all : ${BINS}

%: %.c
	@echo "Building.."
	${CC} $(CFLAGS) $< -o $@

ex11.11: ex11.11.o function.o
	@echo "Linking.."
	$(CC) $(CFLAGS) ex11.11.o function.o -o ex11.11

ex11.11.o: ex11.11.c
	@echo "Creating object.."
	$(CC) $(CFLAGS) -c ex11.11.c

function.o: function.c function.h
	@echo "Creating object.."
	$(CC) $(CFLAGS) -c function.c

clean:
	@echo "Cleanin up..."
	@-rm -v *.o ${BINS}
