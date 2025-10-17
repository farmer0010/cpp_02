#include "Point.hpp"

static Fixed crossProduct(Point const &p1, Point const &p2, Point const &p3)
{
    return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point)
{
    Fixed cp1 = crossProduct(a, b, point);
    Fixed cp2 = crossProduct(b, c, point);
    Fixed cp3 = crossProduct(c, a, point);

    if (cp1 == 0 || cp2 == 0 || cp3 == 0)
        return false;

    bool all_pos = (cp1 > 0) && (cp2 > 0) && (cp3 > 0);
    bool all_neg = (cp1 < 0) && (cp2 < 0) && (cp3 < 0);

    return all_pos || all_neg;
}
