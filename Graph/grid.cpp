#include "grid.h"

Grid::Grid(float w, float h)
{
    //Size
    float size = 50;
    //Draws the x axis lines
    glColor3f(0.15f, 0.15f, 0.15f);
    glLineWidth(2);

    //Optimize
    for(float i = -w, j = w; i <= w, j >= 0; i += size, j -= size)
    {

        //Draw lines on x axis
        glBegin(GL_LINE_LOOP);
            glVertex2f(-w, i);
            glVertex2f(w, i);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glVertex2f(i, -w);
            glVertex2f(i, w);
        glEnd();


        //Draw lines on y axis
        glBegin(GL_LINE_LOOP);
            glVertex2f(-w, j);
            glVertex2f(w, j);
        glEnd();

        glBegin(GL_LINE_LOOP);
            glVertex2f(j, -w);
            glVertex2f(j, w);
        glEnd();

    }

    //Draws the origin of both axis
    glLineWidth(4);

    //Y axis
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
        glVertex2f(0, h);
        glVertex2f(0, -h);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(0, h);
        glVertex2f(25, h-25);
        glVertex2f(-25, h-25);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(0, -h);
        glVertex2f(25, 25-h);
        glVertex2f(-25, 25-h);
    glEnd();

    //X axis
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(-w, 0);
        glVertex2f(w, 0);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(w, 0);
        glVertex2f(w-25, 25);
        glVertex2f(w-25, -25);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(-w, 0);
        glVertex2f(25 - w, 25);
        glVertex2f(25 - w, -25);
    glEnd();
}
