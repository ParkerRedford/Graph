#include "line.h"

Line::Line(Point p1, Point p2) : p1(p1), p2(p2) { }
/*
void Line::draw()
{
    glBegin(GL_LINES);
        p1.childDraw(); p2.childDraw();
    glEnd();
}*/

//Slope equation -- m
float Line::slope()
{
    return (p1.y - p2.y) / (p1.x - p2.x) ;
}

//Fix
float Line::pointSlope()
{
    return p1.y - (p1.x * slope());
}

//Distance from one point to another
float Line::distance()
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

std::ostream& operator<<(std::ostream& os, Line& temp)
{
    glBegin(GL_LINES);
        std::cout << temp.p1 << temp.p2;
    glEnd();

    return os;
}
