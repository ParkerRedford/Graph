#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <fstream>

#include <QMainWindow>
#include <QPushButton>

#include <QList>
#include <QTableView>
#include <QAbstractItemModel>
#include <QStandardItemModel>

#include "glwidget.h"
#include "point.h"
#include "data.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::vector<Point> d;

    QGLWidget gl;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
