#ifndef GRID_H
#define GRID_H

#include <QGLWidget>

#include "line.h"

class Grid : public QGLWidget
{
    Q_OBJECT
public:
    explicit Grid(QWidget *parent = 0);
    Grid(float w, float h);
};

#endif // GRID_H
