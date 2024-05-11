#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const float num1, const float num2) : x(num1), y(num2) {}
Point::Point(const Point &obj) : x(obj.x), y(obj.y) {}
Point &Point::operator=(const Point &obj) { (void)obj; return *this; }
Point::~Point() {}

const Fixed &Point::getX() const { return x; }
const Fixed &Point::getY() const { return y; }