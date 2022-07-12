#include "iostream"

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string& strREF = str;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "ptr address: " << strPTR << std::endl;
	std::cout << "ref address: " << &strREF << std::endl;

	std::cout << "strptr: " << *strPTR << std::endl;
	std::cout << "strref: " << strREF << std::endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   wł
}