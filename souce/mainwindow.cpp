#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    /*connect(ui->tableView, &QTableView::clicked,
            ui->widget, &GLWidget::updateGL);

    QStandardItemModel *model = new QStandardItemModel(0, 2, this); //2 Columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("X")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Y")));

        for(int i = 0; i < ui->widget->data.size(); i++)
        {
            QStandardItem *x = new QStandardItem(QString("%0").arg(ui->widget->data.at(i).x));
            QStandardItem *y = new QStandardItem(QString("%0").arg(ui->widget->data.at(i).y));

            model->setItem(i, 0, x);
            model->setItem(i, 1, y);
        }

        qDebug() << ui->widget->data.size();
*/
    //ui->tableView->setModel(model);

}
MainWindow::~MainWindow()
{
    delete ui;
}
