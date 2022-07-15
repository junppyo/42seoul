#include "iostream"
#include "Data.hpp"
#include "cstdint"

 uintptr_t serialize(Data* ptr)
 {
	 return reinterpret_cast<uintptr_t>(ptr);
 }
 Data* deserialize(uintptr_t raw)
 {
	 return reinterpret_cast<Data*>(raw);
 }

#include <stdio.h>
int main()
{
	Data data(25, "junpkim", "lee");
	uintptr_t ptr = serialize(&data);
	Data *deserialized = deserialize(ptr);
	std::cout << "raw data" << std::endl;
	std::cout << "age: " << data.getAge() << std::endl;
	std::cout << "Id: " << data.getId() << std::endl;
	std::cout << "coalition: " << data.getCoal() << std::endl;
	std::cout << "\nserialized: " << ptr << "\n" << std::endl;
	std::cout << "deserialized" << std::endl;
	std::cout << "age: " << deserialized->getAge() << std::endl;
	std::cout << "Id: " << deserialized->getId() << std::endl;
	std::cout << "coalition: " << deserialized->getCoal() << std::endl;
}