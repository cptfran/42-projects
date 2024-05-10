#include "Fixed.hpp"

void testSubject() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

void testMinMax() {
	Fixed a(1);
	Fixed b(2);
	const Fixed c(-30.04f);
	const Fixed d(+234.1f);
	Fixed min;
	Fixed max;
	Fixed const constMin;
	Fixed const constMax;
	std::cout << "min a(1) b(2) ? " << min.min(a, b) << std::endl;
	std::cout << "max a(1) b(2) ? " << max.max(a, b) << std::endl;
	std::cout << "const min c(-30.04) d(234.1) ? " << constMin.min(c, d) << std::endl;
	std::cout << "const max c(-30.04) d(234.1) ? " << constMax.max(c, d) << std::endl;
}

void testIncreaseDecrease() {
	Fixed a(1);
	Fixed b(1);
	Fixed c(1);
	Fixed d(1);
	std::cout << "++a(1) ? " << ++a << std::endl;
	std::cout << "b++(1) ? " << b++ << " after -> " << b << std::endl;
	std::cout << "--c(1) ? " << --c << std::endl;
	std::cout << "d--(1) ? " << d-- << " after -> " << d << std::endl;
}

void testArithmetic() {
	Fixed a(2.5f);
	Fixed b(3);
	std::cout << "a(2.5) + b(3) ? " << a + b << std::endl;
	std::cout << "a(2.5) - b(3) ? " << a - b << std::endl;
	std::cout << "a(2.5) * b(3) ? " << a * b << std::endl;
	std::cout << "a(2.5) / b(3) ? " << a / b << std::endl;
}

void testComparison() {
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
			&& input != "incr_decr" && input != "min_max") {
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
		testComparison();
		run_test(parser(input));
	} else if (input == "arithmetic") {
		testArithmetic();
		run_test(parser(input));
	} else if (input == "incr_decr") {
		testIncreaseDecrease();
		run_test(parser(input));
	} else if (input == "min_max") {
		testMinMax();
		run_test(parser(input));
	} else if (input == "subject") {
		testSubject();
		input = parser(input);
	}
}

int main() {
	std::string input;
	run_test(parser(input));
	return 0;
}