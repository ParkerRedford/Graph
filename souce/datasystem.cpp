#include "datasystem.h"

DataSystem::DataSystem() { }

DataSystem::DataSystem(std::vector<Point> dataInput, int t)
    : data(dataInput), out(t) { }

std::ostream& operator<<(std::ostream& os, const DataSystem& temp)
{
    switch(temp.out)
    {
    case 0:
        for(Point coor : temp.data)
        {
            std::cout << coor;
        }
        break;
    case 1:
        for(Point coor : temp.data)
        {
            glBegin(GL_LINE_STRIP);
            coor.childDraw();
        }
        glEnd();
        break;
    }

    return os;
}
