#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class Phonebook
{
public:
	void	launch();
private:
	Contact	contact[8];
	void	detect_err_flg();
	void	add_command(size_t cnt);
	void	search_command(size_t cnt);
	void	display_lists(size_t cnt);
	std::string	replace_dot(std::string str);
	void	display_contact_info(size_t cnt);
	void	delete_oldest_contact();
};


#endif