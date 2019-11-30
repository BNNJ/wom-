#include "menu.hpp"
#include <iostream>

Menu::Menu() : current_entry(0) {}

Menu::Menu(std::vector<entry> const& ent) : entries(ent), current_entry(0)
{
	display();
}

void	Menu::add_entry(entry const& ent)
{
	entries.push_back(ent);
}

void	Menu::clear()
{
	entries.clear();
}

void	Menu::next_entry()
{
	highlight_off(current_entry);
//	std::cout << current_entry << std::endl;
	if (current_entry == entries.size() - 1)
		current_entry = 0;
	else
		++current_entry;
	highlight_on(current_entry);
	refresh();
}

void	Menu::prev_entry()
{
	highlight_off(current_entry);
//	std::cout << current_entry << std::endl;
	if (current_entry == 0)
		current_entry = entries.size() - 1;
	else
		--current_entry;
	highlight_on(current_entry);
	refresh();
}

entry	Menu::select() const
{
	return (entries.at(current_entry));
}

void	Menu::display() const
{
	for (std::vector<entry>::size_type i = 0; i < entries.size(); ++i)
		print_menu_line(entries.at(i).stem(), i);
	highlight_on(0);
	refresh();
//	for (std::vector<entry>::size_type i = 0; i < entries.size(); ++i)
//		std::cout << entries.at(i).stem().c_str() << std::endl;
}
