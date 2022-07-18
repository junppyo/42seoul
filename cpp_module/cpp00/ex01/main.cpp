#include "phonebook.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 0 || argv[0])
		;
	Phonebook *phonebook = new Phonebook();
	std::string command;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	while (1)
	{
		std::cout << "select menu\nADD\nSEARCH\nEXIT\n";
		std::cin >> command;
		if (command == "ADD")
		{
			std::cout << "first name: ";
			std::cin >> first_name;
			std::cout << "last name: ";
			std::cin >> last_name;
			std::cout << "nickname: ";
			std::cin >> nickname;
			std::cout << "phone number: ";
			std::cin >> phone_number;
			std::cout << "darkest secret: ";
			std::cin >> darkest_secret;
			phonebook->add_contact(Contact(first_name, last_name, nickname, phone_number, darkest_secret));
		}
		else if (command == "SEARCH")
		{
			int index;
			phonebook->show_all();
			std::cout << "select index : ";
			std::cin >> index;
			if (std::cin.fail())
			{
				std::cout << "wrong index\n";
				std::cin.clear();
				std::cin.ignore();
				continue ;
			}
			if (index - 1 < 0 || index > phonebook->get_contact_num() || index > 8)
			{
				std::cout << "wrong index\n";
				continue ;
			}
			Contact contact = phonebook->get_contact(index - 1);
			std::cout << "\nfirst name: " << contact.get_first_name() << "\nlast name: " << contact.get_last_name() << "\nnickname: " << contact.get_nickname() << "\nphone number: " << contact.get_phone_number() << "\ndarkest secret: " << contact.get_darkest_secret() << "\n\n";
		}
		else if (command == "EXIT")
		{
			break ;
		}
		command.clear();
	}
}
