#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <filesystem>
#include "display.hpp"

using entry = std::filesystem::path;

class EmptyMenuException : public std::exception
{
	const char* what() throw()
	{
		return ("Empty directory");
	}
};

class Menu
{
protected:
	std::vector<entry>				entries;
	std::vector<entry>::size_type	current_entry;

public:
	Menu();
	Menu(std::vector<entry> const& ent);

	void	add_entry(entry const& ent);
	void	clear();
	void	next_entry();
	void	prev_entry();
	entry	select() const;
	void	display() const;
};

#endif /* MENU_HPP */
