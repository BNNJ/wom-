#include <iostream>
#include <filesystem>
#include "display.hpp"
#include "menu.hpp"

namespace fs = std::filesystem;

int		main(int argc, char **argv)
{
	Menu		m;

	if (argc > 1)
	{
		init_ncurses();
		for (auto const& f : fs::directory_iterator(argv[1]))
			m.add_entry(f.path());
		m.display();
		int	c;
		while ((c = getch()) != 'q')
		{
			switch (c)
			{
				case KEY_DOWN:	m.next_entry();	break;
				case KEY_UP:	m.prev_entry();	break;
				case 10:		m.select();		break;
			}
		}
		exit_ncurses();
	}
	else
		std::cout << "no args" << std::endl;
}
