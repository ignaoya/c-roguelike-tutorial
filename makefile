CC = gcc
CFLAGS = -lncurses -lm -I./include/
SOURCES = ./src/*.c

all: rogue run clean

rogue: 
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

run:
	./rogue

clean:
	rm rogue
