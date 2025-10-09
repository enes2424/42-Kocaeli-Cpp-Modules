#include "Point.hpp"

static Fixed determinant_of_2x2_matrix(Point const a, Point const b)
{
	return (Fixed)a.getX() * (Fixed)b.getY() - (Fixed)a.getY() * (Fixed)b.getX();
}

static Fixed find_area(Point const a, Point const b, Point const c)
{
	Fixed area((determinant_of_2x2_matrix(a, b) + determinant_of_2x2_matrix(b, c) + determinant_of_2x2_matrix(c, a)) / 2);
	if (area < 0)
		return area * -1;
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed abp(find_area(a, b, p));
	Fixed acp(find_area(a, c, p));
	Fixed bcp(find_area(b, c, p));
	Fixed abc(find_area(a, b, c));

	if (abp != 0 && acp != 0 && bcp != 0)
		if (abp + acp + bcp == abc)
			return true;
	return false;
}
