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
    Point(int fx, int fy, Color cc, GLenum en);
    Point(int fx, int fy, float s, Color cc, GLenum en);

    //Drawing functions
    void draw();
    void childDraw();

    //Coordinate values
    void setX(float fx);
    void setY(float fy);
    //Point operator-(Point);

    GLenum en;

    int x, y;
    float size;
    Color c;

    friend std::ostream& operator<<(std::ostream&, const Point& temp);
};

#endif // POINT_H
