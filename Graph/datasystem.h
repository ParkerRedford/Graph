#ifndef DATASYSTEM_H
#define DATASYSTEM_H

#include <QtCore>
#include <iostream>
#include "point.h"

class DataSystem
{
public:
    DataSystem();
    DataSystem(std::vector<Point> dataInput, int t);

    std::vector<Point> data;

    int out;

    friend std::ostream& operator<<(std::ostream&, const DataSystem& temp);
};

#endif // DATASYSTEM_H
