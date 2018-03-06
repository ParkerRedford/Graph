#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QSpinBox>

#include "mainwindow.h"

#include "grid.h"
#include "point.h"
#include "line.h"
#include "datasystem.h"
#include "data.h"

#include <QtOpenGL>

#include <QTableWidget>
#include <QMouseEvent>
#include <qDebug>

#include <iostream>
#include <fstream>

#include <sstream>
#include <string>

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0);


    float x2, y2;

    std::vector<Point> system;
    std::vector<Point> data;

    int t;
    DataSystem points;

    QString q;

    void mouseMoveEvent(QMouseEvent *event);

    int mouseX, mouseY, mouseXGL, mouseYGL;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public slots:
    void drawFunction(int f);

private:
    float w, h;

};

#endif // GLWIDGET_H
