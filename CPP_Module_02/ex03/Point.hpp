#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float num1, const float num2);
		Point(const Point &obj);
		Point &operator=(const Point &obj);
		~Point();
		const Fixed &getX() const;
		const Fixed &getY() const;
	private:
		const Fixed x;
		const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);