#include "Phonebook.hpp"

// the stream's error state flags : eofbit, failbit, badbit
void	Phonebook::detect_err_flg(void)
{
	if (std::cin.eof() == true)
	{
		std::cout << "detected eof -> bye!" << std::endl;
		std::exit(EXIT_SUCCESS);
	}
	else if (std::cin.good() != true)
	{
		std::cerr << "detected error bit!!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void	Phonebook::add_command(size_t cnt)
{
	std::string	line;
	std::cout << "Write a first name." << std::endl;
	while (std::getline(std::cin, line))
	{
		if (line[0] == '\0')
		{
			std::cout << "write!!" << std::endl;
			continue;
		}
		contact[cnt].set_first_name(line);
		std::cout << "Thank you" << std::endl;
		break;
	}
	detect_err_flg();
	std::cout << "Write a last name." << std::endl;
	while (std::getline(std::cin, line))
	{
		if (line[0] == '\0')
		{
			std::cout << "write!!" << std::endl;
			continue;
		}
		contact[cnt].set_last_name(line);
		std::cout << "Thank you" << std::endl;
		break;
	}
	detect_err_flg();
	std::cout << "Write a nickname." << std::endl;
	while (std::getline(std::cin, line))
	{
		if (line[0] == '\0')
		{
			std::cout << "write!!" << std::endl;
			continue;
		}
		contact[cnt].set_nickname(line);
		std::cout << "Thank you" << std::endl;
		break;
	}
	detect_err_flg();
	std::cout << "Write a number." << std::endl;
	while (std::getline(std::cin, line))
	{
		if (line[0] == '\0')
		{
			std::cout << "write!!" << std::endl;
			continue;
		}
		contact[cnt].set_number(line);
		std::cout << "Thank you" << std::endl;
		break;
	}
	detect_err_flg();
	std::cout << "Write a darkest secret." << std::endl;
	while (std::getline(std::cin, line))
	{
		if (line[0] == '\0')
		{
			std::cout << "write!!" << std::endl;
			continue;
		}
		contact[cnt].set_darkest_secret(line);
		std::cout << "Thank you" << std::endl;
		break;
	}
	detect_err_flg();
}

std::string  Phonebook::replace_dot(std::string str)
{
	if(str.length() > 10)
	{
		str = str.substr(0,10);
		str[9]='.';
	}
	return(str);
}

void	Phonebook::display_lists(size_t cnt)
{
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	for(size_t i = 0; i < cnt; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << replace_dot(contact[i].get_first_name()) << "|";
		std::cout << std::setw(10) << replace_dot(contact[i].get_last_name()) << "|";
		std::cout << std::setw(10) << replace_dot(contact[i].get_nickname()) << "|" << std::endl;
	}
}

void	Phonebook::display_contact_info(size_t cnt)
{
	std::cout << "enter the index number (or exit): ";
	std::string	line;
	size_t	num;
	while (std::getline(std::cin, line))
	{
		if (line == "exit")
			break;
		num = std::atoi(line.c_str());
		if ((1 <= num && num <= 8) && num <= cnt)
		{
			std::cout << "first name: ";
			std::cout << contact[num - 1].get_first_name() << std::endl;
			std::cout << "last name: ";
			std::cout << contact[num - 1].get_last_name() << std::endl;
			std::cout << "nickname: ";
			std::cout << contact[num - 1].get_nickname() << std::endl;
			std::cout << "number: ";
			std::cout << contact[num - 1].get_number() << std::endl;
			std::cout << "darkest secret: ";
			std::cout << contact[num - 1].get_darkest_secret() << std::endl;
		}
		else
			std::cout << "Bad argument" << std::endl;
		std::cout << "enter the index number (or exit): ";
	}
	detect_err_flg();
}

void	Phonebook::search_command(size_t cnt)
{
	if (cnt == 0)
	{
		std::cout << "First, run the ADD command." << std::endl;
		return ;
	}
	display_lists(cnt);
	display_contact_info(cnt);
}

void	Phonebook::delete_oldest_contact()
{
	for(size_t i = 0; i < 7; i++)
		contact[i] = contact[i + 1];
}

void	Phonebook::launch()
{
	std::string	line;
	size_t	cnt = 0;

	std::cout << "Please enter the command(ex. ADD, SEARCH, EXIT)" << std::endl;
	while (std::getline(std::cin, line))
	{
		if (line == "ADD")
		{
			if (cnt > 7)
			{
				std::cout << "can't store more than 8 contacts!" << std::endl;
				std::cout << "then delete the oldest contact" << std::endl;
				delete_oldest_contact();
				cnt = 7;
			}
			add_command(cnt);
			cnt++;
		}
		else if (line == "SEARCH")
			search_command(cnt);
		else if (line == "EXIT")
		{
			std::cout << "bye!" << std::endl;
			break ;
		}
		else
		{
			std::cerr << "Bad arguments!" << std::endl;
			std::cerr << "The only commands you can use are ADD, SEARCH, and EXIT." << std::endl;
		}
		std::cout << "Please enter the command(ex. ADD, SEARCH, EXIT)" << std::endl;
	}
	detect_err_flg();
}
