#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) { }

void GLWidget::initializeGL()
{
    setMouseTracking(true);
    glClearColor(0, 0, 0, 1);

    std::ifstream file;
    file.open("Data.csv");

    if (file.is_open())
    {
        std::cout << "Open\n";
        while (!file.eof())
        {
            std::string s;
            std::getline(file, s);

            size_t comma = s.find(',', 0);

            std::string sx, sy;
            sx = s.substr(0, comma);
            sy = s.substr(comma + 1, s.length() - comma - 1);

            int x, y;
            x = std::atoi(sx.c_str());
            y = std::atoi(sy.c_str());

            std::vector<int> temp;

            temp.push_back(x);
            temp.push_back(y);

            data.push_back(temp);
        }
        file.close();
    }
    else
    {
        exit(1);
    }
    for(int i = 0; i < data.size() - 1; i++)
    {
        points.data.push_back(Point(data[i][0], data[i][1], Color()));
    }
}

void GLWidget::paintGL()
{
    w = GLWidget::width(), h = GLWidget::height();

    glClear(GL_COLOR_BUFFER_BIT);

    //Can be optimized
    Grid(w, h);

    points.out = t;     //Strip mode
    std::cout << points;

    std::cout << Point(mouseXGL, mouseYGL, Color());
}

void GLWidget::resizeGL(int w, int h)
{
    //Opengl camera setup
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //2d - Near and far = viewing distance
    glOrtho(0, w, h, 0, -1, 1000);

    //Sets origin to center of camera and screen
    glTranslatef(w * 0.5, h * 0.5, 0);
    glRotatef(180, 0, 1, 0);
    glRotatef(180, 0, 0, 1);
    glScalef(0.5, 0.5, 0);
}
void GLWidget::drawFunction(int f)
{
    //Value for strip mode
    t = f;
    updateGL();
}

//Trying to store data into tableWidget
void GLWidget::storeData(){}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    //Calculates coordinates for mouse input values to display on screen under openGL and 2d
    mouseX = event->pos().x() - (w * 0.5);
    mouseY = -(event->pos().y() - (h * 0.5));

    mouseXGL = (event->pos().x() - (w * 0.5))*2;
    mouseYGL = -(event->pos().y() - (h * 0.5))*2;
    updateGL();
}
