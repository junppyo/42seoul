#include "Array.hpp"

int main()
{
	Array<int> arr1((unsigned int)10);
	for (int i = 0 ; i < arr1.size(); i++)
	{
		std::cout << arr1[i] << " ";
	}
	std::cout << "\n";
	Array<int> arr2(arr1);
	for (int i = 0 ; i < arr2.size(); i++)
	{
		std::cout << arr2[i] << " ";
	}
	arr2[1] = 1;
	arr2[2] = 2;
	std::cout << "\n";
	for (int i = 0 ; i < arr2.size(); i++)
		std::cout << arr2[i] << " ";
	std::cout << "\n";
	Array<int> arr3 = arr2;
	for (int i = 0 ; i < arr3.size(); i++)
	{
		std::cout << arr3[i] << " ";
	}
	std::cout << "\n";
}