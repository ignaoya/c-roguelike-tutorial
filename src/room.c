#include <rogue.h>

Room createRoom(int y, int x, int height, int width)
{
	Room newRoom;

	newRoom.pos.y = y;
	newRoom.pos.x = x;
	newRoom.height = height;
	newRoom.width = width;
	newRoom.center.y = y + (int)(height / 2);
	newRoom.center.x = x + (int)(width / 2);

	return newRoom;
}

void addRoomToMap(Room room)
{
	for (int y = room.pos.y; y < room.pos.y + room.height; y++)
	{
		for (int x = room.pos.x; x < room.pos.x + room.width; x++)
		{
			map[y][x].ch = '.';
			map[y][x].walkable = true;
		}
	}
}
