#include "Data.hpp"

Data::Data() : age(0), id(NULL), coal(NULL)
{
}

Data::Data(int _age, std::string _id, std::string _coal) : age(_age), id(_id), coal(_coal)
{

}

int Data::getAge() const
{
	return age;
}

std::string Data::getId() const
{
	return id;
}

std::string Data::getCoal() const
{
	return coal;
}

Data::~Data()
{

}