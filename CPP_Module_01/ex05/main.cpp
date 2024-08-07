#include "Harl.hpp"

std::string parser(std::string input)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (true)
	{
		std::cout << MSG_CHOOSE << std::endl;
		std::getline(std::cin, input);
		for (int i = 0; i < 4; i++)
		{
			if (input == levels[i])
			{
				return input;
			}
		}
		std::cerr << ERR_PARSER_VERIFICATION << std::endl;
	}
}

int main()
{
	Harl harl;
	std::string input;
	input = parser(input);
	if (!input.empty())
	{
		harl.complain(input);
	}
	else
	{
		std::cerr << ERR_PARSER_INPUT << std::endl;
		return 1;
	}
	return 0;
}