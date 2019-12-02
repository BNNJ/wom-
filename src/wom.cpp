#include <iostream>
#include <filesystem>
#include "display.hpp"
#include "menu.hpp"

namespace fs = std::filesystem;

std::vector<entry>	list_files(fs::path const& file)
{
	std::vector<entry>	v;
	try
	{
		for (auto const& f : fs::directory_iterator(file))
			v.push_back(f.path());
	}
	catch (std::exception const& e)
	{
		throw;
	}
	return (v);
}

void	browse(fs::path file)
{
	Menu		m;
	fs::path	current;

	m.display(); refresh();
	while (true)
	{
		if (current != file)
		{
			try
			{
				std::vector<entry> entries = list_files(file);
				clear();
				m = Menu(entries);
				m.display();
				refresh();
				current = file;
			}
			catch (std::exception const& e)
			{
				popup_message(e.what());
				clear();
				m.display();
				refresh();
				file = current;
			}
		}

		bool loop_controls = true;
		while (loop_controls)
		{
			switch (getch())
			{
				case KEY_DOWN:	m.next_entry();				break;
				case KEY_UP:	m.prev_entry();				break;
				case KEY_LEFT:
					file = current.parent_path();
					loop_controls = false;					break;
				case KEY_RIGHT:
					try { file = m.select(); loop_controls = false; }
					catch (...) { file = current; }			break;
				case 'q':		/* Exit browser */			return;
			}
		}
	}
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
