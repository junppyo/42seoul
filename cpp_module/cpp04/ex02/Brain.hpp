#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "iostream"

class Brain
{
	private:
		std::string idea[100];
	public:
		Brain();
		Brain(const Brain&);
		std::string get_idea(int) const;
		void set_idea(int, std::string);
		Brain& operator=(const Brain& input);
		~Brain();
};

std::ostream& operator<<(std::ostream&, const Brain&);
#endif