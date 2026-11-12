
#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc < 4)
	{
		std::cerr << "missing parameter" << std::endl;
		return (1);
	}

	const std::string file_name = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "first string cannot be empty" << std::endl;
		return (1);
	}

	std::ifstream input_file(file_name.c_str());
	if (!input_file)
	{
		std::cerr << "Error: cannot open input file" << std::endl;
		return (1);
	}
	std::ofstream output_file((file_name + ".replace").c_str());
	if (!output_file)
	{
		std::cerr << "Error: cannot open output file" << std::endl;
		return (1);
	}

	std::string	line;
	int			pos;
	std::string	result;
	size_t			found;

	while(std::getline(input_file, line))
	{
		result.clear(); 
		pos = 0;
		found = 0;
		while(true)
		{
			found = line.find(s1, pos);
			if (found == std::string::npos)
			{
				result += line.substr(pos);
				break;
			}
			result += line.substr(pos, found - pos);
			result += s2;
			pos = found + s1.length();
		}
		output_file << result;
		if (!input_file.eof())
			output_file << "\n";
	}
	return (0);
}
