#include "line.h"

Line::Line(Point p1, Point p2, int width) : p1(p1), p2(p2), width(width) { }
//Slope equation -- m
float Line::slope()
{
    return (p1.y - p2.y) / (p1.x - p2.x);
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

void childDraw()
{

}
std::ostream& operator<<(std::ostream& os, const Line& temp)
{
    glLineWidth(temp.width);
    std::cout << temp.p1 << temp.p2;

    return os;
}
