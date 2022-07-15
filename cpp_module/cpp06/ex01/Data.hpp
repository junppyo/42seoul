#ifndef DATA_HPP
# define DATA_HPP
#include "iostream"

class Data
{
	private:
		const int age;
		const std::string id;
		const std::string coal;
	public:
		Data();
		Data(int, std::string, std::string);
		~Data();
		int getAge() const;
		std::string getId() const;
		std::string getCoal() const;
};

#endif