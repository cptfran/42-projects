#include "Harl.hpp"

void Harl::complain(std::string level)
{
	harl_func_t	harl_funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i += 1)
		if (level == levels[i])
			(this->*harl_funcs[i])();
}