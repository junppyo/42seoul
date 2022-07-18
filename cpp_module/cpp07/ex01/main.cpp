#include "iter.hpp"

template <typename T>
void ff(T a)
{
	a = a + 1;
}

int main()
{
	int arr[10];

	for (int i = 0 ; i < 10; i ++ )
		arr[i] = i;
	for (int i = 0 ; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
	iter(arr, 10, ff);
	for (int i = 0 ; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
	char arr2[10];
	for (int i = 0 ; i < 10; i++)
		arr2[i] = 'a' + i;
	for (int i = 0 ; i < 10; i++)
		std::cout << arr2[i] << " ";
	std::cout << "\n";
	iter(arr2, 10, ff);
	for (int i = 0 ; i < 10; i++)
		std::cout << arr2[i] << " ";
}