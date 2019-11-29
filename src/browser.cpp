#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <ncurses.h>
#include "menu.hpp"

using namespace std;
namespace fs = filesystem;

static vector<fs::directory_entry>	list_files(fs::path const& p)
{
	vector<fs::directory_entry>		files;

	for (auto const& f : fs::directory_iterator(p))
		files.push_back(f);
	return (files);
}
/*
static void	init_ncurses(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	refresh();
}
*/

void	browse(fs::path const& file)
{
	vector<fs::directory_entry> files = list_files(file);
	menu::Menu m(files);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		browse(argv[1]);
	else
		cout << "no argument given" << endl;;
}
