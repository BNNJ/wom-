#include <iostream>
#include <filesystem>
#include "display.hpp"
#include "menu.hpp"

namespace fs = std::filesystem;

entry	control(Menu& m, fs::path const& current)
{
	int	c;
	while ((c = getch()) != 'q')
	{
		switch (c)
		{
			case KEY_DOWN:	m.next_entry();				break;
			case KEY_UP:	m.prev_entry();				break;
			case KEY_LEFT:	return (current.parent_path());
			case KEY_RIGHT:	return (m.select());
		}
	}
	return ("");
}

void	browse(fs::path file)
{
	do
	{
		clear();
		Menu		m;
		for (auto const& f : fs::directory_iterator(file))
			m.add_entry(f.path());
		m.display();
		file = control(m, file);
		if (!is_directory(file))
		{
			clear();
			std::string msg = "Do something with " + file.filename().native();
			print_menu_line(msg.c_str(), 0);
			refresh();
			getch();
			break ;
		}
	} while (!file.empty());
}

int		main(int argc, char **argv)
{

	if (argc > 1)
	{
		init_ncurses();
		browse(argv[1]);
		exit_ncurses();
	}
	else
		std::cout << "no args" << std::endl;
}
