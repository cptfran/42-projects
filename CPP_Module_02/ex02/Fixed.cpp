#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0) { std::cout << "\nDefault constructor called" << std::endl; }

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
	fixedPointNum = roundf(val * (1 << numOfFractionalBits)); // round to val * (move 8bits left -> equals 2^8 -> equals 256 -> move the comma)
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const { return (float)fixedPointNum / (1 << numOfFractionalBits); }

int Fixed::toInt() const { return fixedPointNum >> numOfFractionalBits; }

// set output stream for this object, by default output stream cannot handle objects, setting the stream to output obj value converted to float
std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
	os << obj.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed &obj) const { return fixedPointNum > obj.fixedPointNum; }
bool Fixed::operator<(const Fixed &obj) const { return fixedPointNum < obj.fixedPointNum; }
bool Fixed::operator>=(const Fixed &obj) const { return fixedPointNum >= obj.fixedPointNum; }
bool Fixed::operator<=(const Fixed &obj) const { return fixedPointNum <= obj.fixedPointNum; }
bool Fixed::operator==(const Fixed &obj) const { return fixedPointNum == obj.fixedPointNum; }
bool Fixed::operator!=(const Fixed &obj) const { return fixedPointNum != obj.fixedPointNum; }

Fixed Fixed::operator+(const Fixed &obj) const {
	Fixed newObj;
	newObj.fixedPointNum = fixedPointNum + obj.fixedPointNum;
	return newObj;
}

Fixed Fixed::operator-(const Fixed &obj) const {
	Fixed newObj;
	newObj.fixedPointNum = fixedPointNum - obj.fixedPointNum;
	return newObj;
}

Fixed Fixed::operator*(const Fixed &obj) const {
	Fixed newObj;
	newObj.fixedPointNum = (fixedPointNum * obj.fixedPointNum) >> numOfFractionalBits;
	return newObj;
}

Fixed Fixed::operator/(const Fixed &obj) const {
	if (obj.fixedPointNum == 0) {
		std::cerr << ERR_DIV_BY_ZERO << std::endl;
		return 0;
	}
	Fixed newObj;
	newObj.fixedPointNum = (fixedPointNum << numOfFractionalBits) / obj.fixedPointNum;
	return newObj;
}