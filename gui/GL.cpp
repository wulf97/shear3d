#include "GL.h"

GL::GL() : QGLWidget() {
    //Stl *stl = new Stl("/home/alexej/Desktop/cube.stl");
    //Stl *stl = new Stl("/home/alexej/Downloads/der.STL");
    Stl *stl = new Stl("/home/alexej/Desktop/1.stl");
    Polyline pl;
    //pLine.reserve(10);
    for (int i = 0; i < 4; i++) {
        new Cut(stl, 2 + i * 5, pLine[i]);
        pLine[i].print();
    }
}

void GL::initializeGL() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void GL::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(2.0);
    glColor3f(0.65, 0.16, 0.16);
    glBegin(GL_LINE_STRIP);

    //qDebug() << this->pLine.size();
    for (int i = 0; i < 4; i++) {
    for (int j = 0; j < this->pLine[i].size(); j++) {
        glVertex2f(pLine[i].get(j).getX(), pLine[i].get(j).getY());
    }}

    glEnd();
}

void GL::resizeGL(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
    glViewport(0, 0, (GLint)w, (GLint)h);
}
