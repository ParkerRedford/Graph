#include "color.h"

//Default white
Color::Color()
{
    glColor3ub(255, 255, 255);
}

//Declare color
Color::Color(float r, float g, float b)
{
    glColor3ub(r, g, b);
}
