#include <rogue.h>

void cursesSetup(void)
{
	initscr();
	noecho();
	curs_set(0);
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
