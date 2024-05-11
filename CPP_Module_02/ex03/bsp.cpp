#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	// vector product (cross product):
	// The vector product, also known as the cross product, is a mathematical operation that takes two vectors and 
	// produces another vector. It is often used to find the vector perpendicular to two given vectors

	// TRIANGLE abc AREA:
	// Vector ab = b - a
	Fixed vectorABX(b.getX() - a.getX()); // ab.x
	Fixed vectorABY(b.getY() - a.getY()); // ab.y

	// Vector ac = c - a
	Fixed vectorACX(c.getX() - a.getX()); // ac.x
	Fixed vectorACY(c.getY() - a.getY()); // ac.y

	// Vector product ab x ac = ab.x * ac.y - ab.y * ac.x
	Fixed productABC(vectorABX * vectorACY - vectorABY * vectorACX);

	// The area of the triangle is half the absolute value of the vector product
	// Area = 0.5 * ||ab x ac||
	Fixed areaABC(productABC / 2);
	if (areaABC < 0)
		areaABC = areaABC * -1;

	// TRIANGLE abp AREA:
	// Vector ab = b - a (vectorABX, vectorABY)

	// Vector ap = p - a
	Fixed vectorAPX(point.getX() - a.getX()); // ap.x
	Fixed vectorAPY(point.getY() - a.getY()); // ap.y

	// Vector product ab x ap = ab.x * ap.y - ab.y * ap.x
	Fixed productABP(vectorABX * vectorAPY - vectorABY * vectorAPX);

	// The area of the triangle is half the absolute value of the vector product
	// Area = 0.5 * ||ab x ap||
	Fixed areaABP(productABP / 2);
	if (areaABP < 0)
		areaABP = areaABP * -1;

	// TRIANGLE acp
	// Vector product ac x ap = ac.x * ap.y - ac.y * ap.x
	Fixed productACP(vectorACX * vectorAPY - vectorACY * vectorAPX);
	
	// The area of the triangle is half the absolute value of the vector product
	// Area = 0.5 * ||ac x ap|
	Fixed areaACP(productACP / 2);
	if (areaACP < 0)
		areaACP = areaACP * -1;

	// TRIANGLE bcp
	// Vector bc = c - b
	Fixed vectorBCX(c.getX() - b.getX()); // bc.x
	Fixed vectorBCY(c.getY() - b.getY()); // bc.y

	// Vector bp = p - b
	Fixed vectorBPX(point.getX() - b.getX()); // bp.x
	Fixed vectorBPY(point.getY() - b.getY()); // bp.y

	// Vector product bc x bp = bc.x * bp.y - bc.y * bp.x
	Fixed productBCP(vectorBCX * vectorBPY - vectorBCY * vectorBPX);
	
	// The area of the triangle is half the absolute value of the vector product
	// Area = 0.5 * ||bc x bp|
	Fixed areaBCP(productBCP / 2);
	if (areaBCP < 0)
		areaBCP = areaBCP * -1;
	
	// If any of the products of small triangles equals 0, then the point is on the edge
	if (productABP == 0 || productACP == 0 || productBCP == 0)
		return false;

	// If area of a whole triangle is equal to a sum of areas of smaller triangles,
	// the point is inside the triangle
	if (areaABC == areaABP + areaACP + areaBCP)
		return true;
	return false;
}
