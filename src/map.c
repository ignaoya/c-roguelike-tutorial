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
			tiles[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
			tiles[y][x].walkable = false;
		}
	}

	return tiles;
}

Position setupMap(void)
{
	int y, x, height, width, n_rooms;
	n_rooms =  (rand() % 11) + 5;
	Room* rooms = calloc(n_rooms, sizeof(Room));
	Position start_pos;

	for (int i = 0; i < n_rooms; i++)
	{
		y = (rand() % (MAP_HEIGHT - 10)) + 1;
		x = (rand() % (MAP_WIDTH - 20)) + 1;
		height = (rand() % 7) + 3;
		width = (rand() % 15) + 5;
		rooms[i] = createRoom(y, x, height, width);
		addRoomToMap(rooms[i]);

		if (i > 0)
		{
			connectRoomCenters(rooms[i-1].center, rooms[i].center);
		}
	}

	start_pos.y = rooms[0].center.y;
	start_pos.x = rooms[0].center.x;

	free(rooms);

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
