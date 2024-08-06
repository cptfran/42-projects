#include "Harl.hpp"

void Harl::complainFilter(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	funcHarl harlComplaints[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			break;
		}
	}
	switch (i)
	{
		case 0:
			(this->*harlComplaints[0])();
		case 1:
			(this->*harlComplaints[1])();
		case 2:
			(this->*harlComplaints[2])();
		case 3:
			(this->*harlComplaints[3])();
			break;
		default:
			std::cout << DEFAULT << std::endl;
	}
}

void Harl::debug()
{
	std::cout << DEBUG << std::endl;
}

void Harl::info()
{
	std::cout << INFO << std::endl;
}

void Harl::warning()
{
	std::cout << WARNING << std::endl;
}

void Harl::error()
{
	std::cout << ERROR << std::endl;
}