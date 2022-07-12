#include "Karen.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	std::string str(argv[1]);
	Karen karen = Karen();
	karen.complain(str);
}