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
	current_entry = 0;
}

void	Menu::next_entry()
{
	if (!entries.empty())
	{
		highlight_off(current_entry);
		if (current_entry == entries.size() - 1)
			current_entry = 0;
		else
			++current_entry;
		highlight_on(current_entry);
		refresh();
	}
}

void	Menu::prev_entry()
{
	if (!entries.empty())
	{
		highlight_off(current_entry);
		if (current_entry == 0)
			current_entry = entries.size() - 1;
		else
			--current_entry;
		highlight_on(current_entry);
		refresh();
	}
}

entry	Menu::select() const
{
	if (entries.empty())
		throw "Empty Directory";
	return (entries.at(current_entry));
}

void	Menu::display() const
{
	if (entries.empty())
		print_menu_line("< Empty directory >", 0);
	else
	{
		for (std::vector<entry>::size_type i = 0; i < entries.size(); ++i)
			print_menu_line(entries.at(i).stem(), i);
		highlight_on(current_entry);
	}
	refresh();
}
