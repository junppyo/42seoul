#include "iostream"
#include "fstream"

std::string file_read(char *filename)
{
	std::ifstream in(filename);

	if (!in.is_open())
		return (0);
	std::string str;
	in >> str;
	while (in.tellg() > std::ios::end)
	{
		std::string tmp;
		in >> tmp;
		if (in)
		{
			str.append("\n");
			str.append(tmp);
		}
	}
	return (str);
}

std::string _replace(std::string str, std::string from, std::string to)
{
	std::string ret;
	int loc;
	int	start;

	start = 0;
	loc = 0;
	while ((loc = str.find(from, start)) < str.length())
	{
		if (start != loc)
			ret.append(str.substr(start, loc - start));
		ret.append(to);
		start = loc + from.length();
	}
	ret.append(str.substr(start, str.length() - start));
	return ret;
}

void	file_write(std::string str, std::string file_name)
{
	file_name.append(".replace");
	std::ofstream out(file_name);
	out << str;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	std::string str;
	std::string replace;
	std::string argv1(argv[1]);
	std::string argv2(argv[2]);
	std::string argv3(argv[3]);
	std::string rep;

	str = file_read(argv[1]);
	rep = _replace(str, argv2, argv3);
	file_write(rep, argv[1]);
}