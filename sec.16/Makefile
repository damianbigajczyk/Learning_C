# -*- MakeFile -*-
#  Usage:
#  make 	# compile all binary
#  make clean 	# remove all binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g
RM = -rm -vf *.o ${BIN}

SRC := $(wildcard *.c)
BIN := $(SRC:%.c=%)

all: ${BIN}

%: %.c
	@echo "Building.."
	$(CC) $(CGLAGS) $< -o $@ -lm

clean:
	@echo "Cleaning up..."
	@$(RM)
	




