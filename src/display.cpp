#include "display.hpp"
#include <ncurses.h>


static int	x_offset;
static int	y_offset;
static int	max_x;
static int	max_y;
static int	menu_width;

void	init_ncurses()
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	getmaxyx(stdscr, max_y, max_x);
	menu_width = max_x - 10;
	x_offset = 5;
	y_offset = 5;
	refresh();
}

void	exit_ncurses()
{
	curs_set(1);
	endwin();
}

void	print_menu_line(std::string const& line, int y)
{
	mvprintw(y + y_offset, x_offset + 2, "%s", line.c_str());
}

void	highlight_on(int y)
{
	mvchgat(y + y_offset, x_offset, menu_width, A_REVERSE, 0, NULL);
}

void	highlight_off(int y)
{
	mvchgat(y + y_offset, x_offset, menu_width, A_NORMAL, 0, NULL);
}
