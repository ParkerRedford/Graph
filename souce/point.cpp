#include "point.h"

Point::Point(int fx, int fy) : x(fx), y(fy) { }
Point::Point(int fx, int fy, Color cc, GLenum en) : x(fx), y(fy), c(cc), en(en) { }
Point::Point(int fx, int fy, float s,  Color cc, GLenum en) : x(fx), y(fy), size(s), c(cc),
en(en) { }

void Point::childDraw()
{
    glPointSize(1);
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
    glPointSize(temp.size);
    temp.c;
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    glBegin(temp.en);
            glVertex2f(temp.x, temp.y);
    return os;
}
