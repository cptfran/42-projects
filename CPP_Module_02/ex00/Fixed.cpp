#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator=(obj);
}

Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		this->setRawBits(obj.getRawBits());
	}
	return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointNum;
}

void Fixed::setRawBits(int const raw) { fixedPointNum = raw; }