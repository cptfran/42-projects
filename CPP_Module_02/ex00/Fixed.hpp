#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
	private:
		int fixedPointNum;
		static const int numOfFractionalBits = 8;
};