#include <ncurses.h>

typedef Position
{
	int y;
	int x;
} Position;

typedef Entity
{
	Position pos;
	char ch;
} Entity;
