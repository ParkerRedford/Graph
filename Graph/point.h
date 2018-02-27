#ifndef POINT_H
#define POINT_H

#include <QGLWidget>

#include "color.h"

class Point
{
public:
    //Constructors
    Point();
    Point(int fx, int fy);
    Point(int fx, int fy, Color c);

    //Drawing functions
    void draw();
    void childDraw();

    //Coordinate values
    void setX(float fx);
    void setY(float fy);
    //Point operator-(Point);

    int x, y;
    Color c;

    friend std::ostream& operator<<(std::ostream&, const Point& temp);
};

#endif // POINT_H
