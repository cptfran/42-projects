#include "Harl.hpp"

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	funcHarl harlComplaints[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*harlComplaints[i])();
			return;
		}
	}
}

void Harl::debug() { std::cout << DEBUG << std::endl; }
void Harl::info() { std::cout << INFO << std::endl; }
void Harl::warning() { std::cout << WARNING << std::endl; }
void Harl::error() { std::cout << ERROR << std::endl; }