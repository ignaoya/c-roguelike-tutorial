#include <rogue.h>

void drawMap(void)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			mvaddch(y, x, map[y][x].ch | map[y][x].color);
		}
	}
}

void drawEntity(Entity* entity)
{
	mvaddch(entity->pos.y, entity->pos.x, entity->ch | entity->color);
}

void drawEverything(void)
{
	clear();
	drawMap();
	drawEntity(player);
}
