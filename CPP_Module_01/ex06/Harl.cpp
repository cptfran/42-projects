#include "Harl.hpp"

void Harl::complainFilter(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	funcHarl harlComplaints[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		switch (level.compare(levels[i])) {
			case 0:
				for (int j = i; j < 4; j++)
					(this->*harlComplaints[j])();
				break;
		}
	}

}

void Harl::debug() { std::cout << DEBUG << std::endl; }
void Harl::info() { std::cout << INFO << std::endl; }
void Harl::warning() { std::cout << WARNING << std::endl; }
void Harl::error() { std::cout << ERROR << std::endl; }