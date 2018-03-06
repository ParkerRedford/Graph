#ifndef LINE_H
#define LINE_H

#include <QGLWidget>

#include <iostream>
#include "point.h"
#include <cmath>

class Line
{
public:
    Line(Point p1, Point p2, int width);

    float slope();
    float pointSlope();
    float distance();

    void childDraw();

    Point p1;
    Point p2;
    int width;

    friend std::ostream& operator<<(std::ostream& os, const Line& temp);
};

#endif // LINE_H
