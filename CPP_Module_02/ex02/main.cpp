#include "Fixed.hpp"

// void test_subject() {

// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 99.99 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }

void test_increment_decrement() {
	Fixed a(0.5f);
	std::cout << "++a ? " << ++a << std::endl;
	std::cout << "a++ ?" << a++ << std::endl;
	std::cout << "--a ?" << --a << std::endl;
	std::cout << "a-- ?" << a-- << std::endl;
}

void test_arithmetic() {
	Fixed a(2.5f);
	Fixed b(3);
	std::cout << "a(2.5) + b(3) ? " << a + b << std::endl;
	std::cout << "a(2.5) - b(3) ? " << a - b << std::endl;
	std::cout << "a(2.5) * b(3) ? " << a * b << std::endl;
	std::cout << "a(2.5) / b(3) ? " << a / b << std::endl;
}

void test_comparison() {
	Fixed a(100);
	Fixed b(99.99f);
	Fixed c(99.99f);
	std::cout << "Is a(100) > b(99.99)? " << (a > b) << std::endl;
	std::cout << "Is a(100) < b(99.99)? " << (a < b) << std::endl;
	std::cout << "Is b(99.99) >= c(99.99)? " << (b >= c) << std::endl;
	std::cout << "Is b(99.99) <= c(99.99)? " << (b <= c) << std::endl;
	std::cout << "Is b(99.99) == c(99.99)? " << (b == c) << std::endl;
	std::cout << "Is b(99.99) == a(100)? " << (b == a) << std::endl;
	std::cout << "Is b(99.99) != a(100)? " << (b != a) << std::endl;
}

std::string parser(std::string input) {
	while (1) {
		std::cout << MSG_ASK << std::endl;
		std::cout << GRAY;
		std::getline(std::cin, input);
		std::cout << RESET;
		if (input != "exit" && input != "comparison" && input != "subject" && input != "arithmetic"
			&& input != "increment_decrement") {
			std::cerr << ERR_WRONG_INPUT << std::endl;
			continue;
		}
		return input;
	}
}

void run_test(std::string input) {
	if (input == "exit") {
		std::cout << MSG_EXIT << std::endl;
		return ;
	} else if (input == "comparison") {
		test_comparison();
		run_test(parser(input));
	} else if (input == "arithmetic") {
		test_arithmetic();
		run_test(parser(input));
	} else if (input == "increment_decrement") {
		test_increment_decrement();
		run_test(parser(input));
	}
	// else if (input == "subject") {
	// 	test_subject();
	// 	input = parser(input);
	// }
}

int main() {
	std::string input;
	run_test(parser(input));
	return 0;
}