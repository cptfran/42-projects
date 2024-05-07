#include <iostream>

#define RED "\033[31m"
#define LIGHT_GREEN "\033[92m"
#define BLUE "\033[94m"
#define YELLOW "\033[33m"
#define GRAY "\033[90m"
#define RESET "\033[0m"

#define DEBUG LIGHT_GREEN "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" RESET
#define INFO LIGHT_GREEN "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" RESET
#define WARNING LIGHT_GREEN "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." RESET
#define ERROR LIGHT_GREEN "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." RESET

#define ERR_PARSER_VERIFICATION RED "Error: wrong input, choose one of these: 'DEBUG', 'INFO', 'WARNING, 'ERROR'" RESET
#define ERR_PARSER_INPUT RED "Error: input issue, try to run the program again" RESET

#define MSG_CHOOSE GRAY "Choose level ('DEBUG', 'INFO', 'WARNING', 'ERROR')" RESET

class Harl {
	public:
		void complainFilter(std::string level);
	private:
		typedef void (Harl::*funcHarl)();
		void debug();
		void info();
		void warning();
		void error();
};