#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator=(obj);
}

Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		fixedPointNum = obj.fixedPointNum;
	}
	return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const int val) : fixedPointNum(val << numOfFractionalBits) { std::cout << "Int constructor called" << std::endl; }

Fixed::Fixed(const float val) {
	fixedPointNum = roundf(val * (1 << numOfFractionalBits)); // round to val * (move 8bits left -> equals 2^8 -> equals 256 -> get rid of commas)
	std::cout << "Float constructor called" << std::endl;
}


float Fixed::toFloat() const { return (float)fixedPointNum / (1 << numOfFractionalBits); }

int Fixed::toInt() const { return fixedPointNum >> numOfFractionalBits; }

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
	os << obj.toFloat();
	return os;
}