#include <iostream>
#include <cmath>

#define RED "\033[31m"
#define LIGHT_GREEN "\033[92m"
#define BLUE "\033[94m"
#define YELLOW "\033[33m"
#define GRAY "\033[90m"
#define RESET "\033[0m"

#define MSG_ASK LIGHT_GREEN "Which test? ('comparison', 'arithmetic', 'incr_decr', 'min_max', 'subject')\nUse 'exit' to exit the program" RESET
#define MSG_EXIT LIGHT_GREEN "exit" RESET

#define ERR_WRONG_INPUT RED "Error: test not found" RESET
#define ERR_DIV_BY_ZERO RED "\nError: divison by 0" RESET


class Fixed {
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
		// 'friend' allows 'operator<<' to manipulate this class private members
		friend std::ostream &operator<<(std::ostream &os, const Fixed &obj);
		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;
		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static Fixed &min(Fixed &obj1, Fixed &obj2);
		const static Fixed &min(const Fixed &obj1, const Fixed &obj2);
		static Fixed &max(Fixed &obj1, Fixed &obj2);
		const static Fixed &max(const Fixed &obj1, const Fixed &obj2);
	private:
		int fixedPointNum;
		static const int numOfFractionalBits = 8;
};