#include <rogue.h>

Tile** createMapTiles(void)
{
	Tile** tiles = calloc(MAP_HEIGHT, sizeof(Tile*));

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			tiles[y][x].ch = '#';
			tiles[y][x].walkable = false;
		}
	}

	return tiles;
}

Position setupMap(void)
{
	Position start_pos = { 10, 50 };

	for (int y = 5; y < 15; y++)
	{
		for (int x = 40; x < 60; x++)
		{
			map[y][x].ch = '.';
			map[y][x].walkable = true;
		}
	}

	return start_pos;
}

void freeMap(void)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		free(map[y]);
	}
	free(map);
}
