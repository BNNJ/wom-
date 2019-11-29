#include "menu.hpp"
#include <ncurses.h>
#include <iostream>

using namespace menu;

//Entry::Entry(std::filesystem::path const& p) : path(p), name(p.stem()) {}

Menu::Menu(std::vector<std::filesystem::directory_entry> const& ent)
	: entries(ent), current_entry(0)
{
	display();
}

void	Menu::next_entry()
{
	if (current_entry == entries.size() - 1)
		current_entry = 0;
	else
		++current_entry;
	display();
}

void	Menu::prev_entry()
{
	if (current_entry == 0)
		current_entry = entries.size() - 1;
	else
		--current_entry;
	display();
}

void	Menu::display() const
{
	std::cout << "HELLO THIS IS MENU" << std::endl;
	for (auto const& e : entries)
		std::cout << static_cast<std::string>(e.path().stem()) << std::endl;
}

std::filesystem::directory_entry	Menu::select() const
{
	return (entries.at(current_entry));
}
