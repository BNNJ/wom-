#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <ncurses.h>
#include <string>

void	init_ncurses();
void	exit_ncurses();
void	print_menu_line(std::string const& line, int y);
void	highlight_on(int y);
void	highlight_off(int y);

#endif /* DISPLAY_HPP */
