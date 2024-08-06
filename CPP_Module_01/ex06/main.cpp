#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << ERR_PARSER_INPUT << std::endl;
		return 1;
	}
	Harl harl;
	std::string level = argv[1];
	harl.complainFilter(level);
	return 0;
}