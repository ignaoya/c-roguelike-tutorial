#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct
{
	int y;
	int x;
} Position;

typedef struct
{
	Position pos;
	char ch;
} Entity;


// player.c functions
Entity* createPlayer(Position start_pos);
void handleInput(int input);

// externs
extern Entity* player;

#endif
