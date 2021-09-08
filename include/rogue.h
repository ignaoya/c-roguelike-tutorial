#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

// color pairs
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2

typedef struct
{
	int y;
	int x;
} Position;

typedef struct
{
	char ch;
	int color;
	bool walkable;
} Tile;

typedef struct
{
	int height;
	int width;
	Position pos;
	Position center;
} Room;

typedef struct
{
	Position pos;
	char ch;
	int color;
} Entity;

//draw.c functions
void drawMap(void);
void drawEntity(Entity* entity);
void drawEverything(void);

//engine.c functions
void cursesSetup(void);
void gameLoop(void);
void closeGame(void);

//map.c functions
Tile** createMapTiles(void);
Position setupMap(void);
void freeMap(void);

// player.c functions
Entity* createPlayer(Position start_pos);
void handleInput(int input);
void movePlayer(Position newPos);

// room.c functions
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);
void connectRoomCenters(Position centerOne, Position centerTwo);

// externs
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Entity* player;
extern Tile** map;

#endif
