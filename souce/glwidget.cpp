#include "glwidget.h"
#include "data.h"

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{

}

void GLWidget::initializeGL()
{
    setMouseTracking(true);
    glClearColor(0, 0, 0, 1);

/*
    glFormat = QGLFormat::defaultFormat();
    glFormat.setVersion(2, 0);
    glFormat.setProfile(QGLFormat::CoreProfile);
    glFormat.setSampleBuffers(true);
    //QGLWidget w2(glFormat);
    this->glFormat;
    this->show();
    //qDebug() << this.context()->requestedFormat();
    //qDebug() << this.context()->format();
*/
    /*std::ofstream data;
    data.open("data");
    double PI = 3.14159265359;
    double toRadian = PI/180;

    data.open("data");
    if(data.is_open())
    {
        for(int i = -w; i < w; i++)
        {
            d.push_back(Point(i, 100*cos(i*toRadian)));
            data << i << ", " << (double)(100*cos(i*toRadian)) << std::endl;
        }
        data.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno);
*/
}

void GLWidget::paintGL()
{

    w = GLWidget::width(), h = GLWidget::height();

    glClear(GL_COLOR_BUFFER_BIT);
    //std::ofstream data;
    //Can be optimized
    Grid(w, h);

    //double PI = 3.14159265359;
    double PI = acos(-1);
    double toRadians = (PI / 180) / 3.6;

    //data.open("data");

    //Draw the graph
    for(int i = -w; i <= w; i++)
    {
        double angle = i * toRadians;

        double x = i;
        double y = 200*sin(angle);

        std::cout << Point(x, y, 1, Color(), GL_LINE_STRIP);

        //data.push_back(Point(x, y));
        //qDebug() << data.size();
        //data << x << ", " << (double)(y) << std::endl;
    }
    glEnd();
}

void GLWidget::resizeGL(int w, int h)
{
    double PI = acos(-1);
    double toRadians = (PI / 180) / 3.6;

    for(int i = -w; i <= w; i++)
    {
        double angle = i * toRadians;

        double x = i;
        double y = 200*sin(angle);

        data.push_back(Point(x, y));
    }
    //qDebug() << data.size()-1;

    //Opengl camera setup

    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //2d - Near and far = viewing distance
    glOrtho(w, 0, h, 0, -1, 1000);

    //Sets origin to center of camera and screen
    glTranslatef(w * 0.5, h * 0.5, 0);
    glRotatef(180, 0, 1, 0);
    glRotatef(180, 1, 0, 0);
    glScalef(0.5, 0.5, 0);
}
void GLWidget::drawFunction(int f)
{
    //Value for strip mode
    t = f;
    updateGL();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    //Calculates coordinates for mouse input values to display on screen under openGL and 2d
    mouseX = event->pos().x() - (w * 0.5);
    mouseY = -(event->pos().y() - (h * 0.5));

    mouseXGL = (event->pos().x() - (w * 0.5))*2;
    mouseYGL = -(event->pos().y() - (h * 0.5))*2;

    //qDebug() << mouseXGL << ", " << mouseYGL;
    updateGL();
}
