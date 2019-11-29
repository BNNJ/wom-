#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <filesystem>

namespace menu
{
/*
class Entry
{
public:
	Entry(std::filesystem::path const& p);

	std::string	get_name() const { return name; }
	std::string	get_path() const { return path; }

protected:
	std::string				name;
	std::filesystem::path	path;
};
*/
class Menu
{
public:
	Menu(std::vector<std::filesystem::directory_entry> const& ent);

	void	display() const;
	void	next_entry();
	void	prev_entry();
	std::filesystem::directory_entry	select() const;

protected:
	std::vector<std::filesystem::directory_entry>				entries;
	std::vector<std::filesystem::directory_entry>::size_type	current_entry;
};

} /* end of namespace menu */

#endif /* MENU_HPP */
