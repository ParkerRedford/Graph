#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QSpinBox>

#include "mainwindow.h"

#include "grid.h"
#include "point.h"
#include "line.h"
#include "datasystem.h"

#include <QTableWidget>
#include <QMouseEvent>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0);

    float x2, y2;

    std::vector<Point> system;
    int t;
    DataSystem points;
    std::vector< std::vector<int> > data;
    QString q;

    //QTableWidget* tableWidget;

    void GLWidget::mouseMoveEvent(QMouseEvent *event);

    int mouseX, mouseY, mouseXGL, mouseYGL;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);



public slots:
    void drawFunction(int f);
    void storeData();

private:
    float w, h;

};

#endif // GLWIDGET_H
