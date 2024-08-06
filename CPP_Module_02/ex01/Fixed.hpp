#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &obj);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
	friend std::ostream &operator<<(std::ostream &os, const Fixed &obj);
private:
	int fixedPointNum;
	static const int numOfFractionalBits = 8;
};