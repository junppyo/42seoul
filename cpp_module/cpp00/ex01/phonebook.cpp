#include "phonebook.hpp"

Phonebook::Phonebook()
{
	this->contact_num = 0;
}

void Phonebook::add_contact(Contact contact)
{
	this->contact[contact_num % 8] = contact;
	contact_num++;
}

int Phonebook::get_contact_num()
{
	return (this->contact_num);
}

Contact Phonebook::get_contact(int n)
{
	return (this->contact[n]);
}

std::string convert(std::string s)
{
	int	i;

	if (s.length() > 10)
	{
		s = s.substr(0, 9);
		s.append(".");
	}
	else
	{
		i = s.length();
		while (i++ < 10)
			s.append(" ");
	}
	return (s);
}

void Phonebook::show_all()
{
	std::string tmp;
	Contact contact;
	int	index;

	index = 0;
	std::cout << "index     |first name|last name |nickname  |\n";
	while (++index <= this->get_contact_num() && index <= 8)
	{
		contact = get_contact(index - 1);
		tmp = convert(std::to_string(index));
		std::cout << tmp << "|";
		tmp.clear();
		tmp = convert(contact.get_first_name());
		std::cout << tmp << "|";
		tmp.clear();
		tmp = convert(contact.get_last_name());
		std::cout << tmp << "|";
		tmp.clear();
		tmp = convert(contact.get_nickname());
		std::cout << tmp << "|\n";
		tmp.clear();
	}
}
