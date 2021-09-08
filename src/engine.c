#include <rogue.h>

void cursesSetup(void)
{
	initscr();
	noecho();
	curs_set(0);

	if (has_colors())
	{
		start_color();

		init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
		init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);
	}
}

void gameLoop(void)
{
	int ch;

	drawEverything();

	while(ch = getch())
	{
		if (ch == 'q')
		{
			break;
		}

		handleInput(ch);
		drawEverything();
	}
}

void closeGame(void)
{
	endwin();
	free(player);
}
