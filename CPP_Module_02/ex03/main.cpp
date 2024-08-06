#include "Point.hpp"

int main()
 {
	{
		Point a(0,0);
		Point b(10,0);
		Point c(0,10);
		Point p(1,1);
		std::cout << "a(0,0) b(10,0) c(0,10) p(1,1) -> " << bsp(a, b, c, p) << std::endl;
	}
	{
		Point a(0,0);
		Point b(10,0);
		Point c(0,10);
		Point p(15,15);
		std::cout << "a(0,0) b(10,0) c(0,10) p(15,15) -> " << bsp(a, b, c, p) << std::endl;
	}
	{
		Point a(0,0);
		Point b(10,0);
		Point c(0,10);
		Point p(5,0);
		std::cout << "a(0,0) b(10,0) c(0,10) p(5,0) -> " << bsp(a, b, c, p) << std::endl;
	}
	return 0;
}