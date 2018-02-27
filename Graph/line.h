#ifndef LINE_H
#define LINE_H

#include <QGLWidget>

#include <iostream>
#include "point.h"
#include <cmath>

class Line
{
public:
    Line(Point p1, Point p2);

    float slope();
    float pointSlope();
    float distance();

    Point p1;
    Point p2;

    friend std::ostream& operator<<(std::ostream& os, Line& temp);
};

#endif // LINE_H
