#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include "iostream"

class Phonebook
{
	private:
		Contact contact[8];
		int		contact_num;

	public:
		Phonebook();
		void add_contact(Contact contact);
		void search_contact(int index);
		int get_contact_num();
		Contact get_contact(int index);
		void get_contact_info(int index);
		void show_all();
};

#endif
