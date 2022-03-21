#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <string>

class Contact
{
public:
	void	set_first_name(std::string);
	void	set_last_name(std::string);
	void	set_nickname(std::string);
	void	set_number(std::string);
	void	set_darkest_secret(std::string);
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nickname();
	std::string	get_number();
	std::string	get_darkest_secret();
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	number;
	std::string	darkest_secret;
};

#endif
