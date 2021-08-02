#include <ncurses.h>

int main(void)
{
	initscr();
	noecho();
	curs_set(0);


	while(getch() != 'q')
	{
		mvaddch(10, 20, '@');
	}

	endwin();

	return 0;
}
