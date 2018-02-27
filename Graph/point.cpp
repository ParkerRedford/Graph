#include "point.h"

Point::Point(int fx, int fy) : x(fx), y(fy) { }
Point::Point(int fx, int fy, Color cc) : x(fx), y(fy), c(cc) { }

void Point::childDraw()
{
    glVertex2f(x, y);
}
void Point::setX(float fx)
{
   x = fx;
}
void Point::setY(float fy)
{
   y = fy;
}
std::ostream& operator<<(std::ostream& os, const Point& temp)
{
    glPointSize(10);
    temp.c;
    glBegin(GL_POINTS);
            glVertex2f(temp.x, temp.y);
    glEnd();
    return os;
}
