#include "grid.h"

Grid::Grid(float w, float h)
{
    //Size
    int size = 200;

    //Draws the x axis lines

    int s = 1;
    Color c = Color(60, 60, 60);
    GLenum l = GL_LINE_LOOP;
    GLenum lines = GL_LINES;

    for(float i = -w, j = w; i <= w, j >= 0; i += size, j -= size)
    {

        if(i != 0 && j != 0)
        {
            std::cout << Line(Point(-w, i, c, l), Point(w, i, c, l), s);
            glEnd();

            std::cout << Line(Point(i, w, c, l), Point(i, -w, c, l), s);
            glEnd();

            std::cout << Line(Point(-h, j, c, l), Point(h, j, c, l), s);
            glEnd();

            std::cout << Line(Point(j, -h, c, l), Point(j, h, c, l), s);
            glEnd();
        }
    }
    //glLineWidth(1);
    /*
    for(int i = 0; i < w; i += size)
    {
        if(i != 0)
        {
            std::cout << Line(Point(i, h, c, l), Point(i, -h, c, l));
            glEnd();
        }
    }*/

    //Draws the origin of both axis
    //glLineWidth(2);

    //Y axis
    Color b = Color(0, 0, 255);

    std::cout << Line(Point(0, h, b, lines), Point(0, -h, b, lines), 1);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(0, h);
        glVertex2f(20, h-20);
        glVertex2f(-20, h-20);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(0, -h);
        glVertex2f(25, 25-h);
        glVertex2f(-25, 25-h);
    glEnd();

    //X axis
    Color r = Color(255, 0, 0);

    std::cout << Line(Point(-w, 0, r, lines), Point(w, 0, r, lines), 1);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(w, 0);
        glVertex2f(w-20, 20);
        glVertex2f(w-20, -20);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(-w, 0);
        glVertex2f(20 - w, 20);
        glVertex2f(20 - w, -20);
    glEnd();
}
