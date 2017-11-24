#include "GL.h"

GL::GL(Cut *cut, Tcor gap, Tcor x, Tcor y, Tcor w, Tcor h) : QGLWidget() {
    this->cut = cut;
    this->_gap = gap;
    this->_x = x;
    this->_y = y;
    this->_w = w;
    this->_h = h;
}

void GL::initializeGL() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glRotated(45, -1.0, 1.0, 1.0);
}

void GL::paintGL() {
    Tcor x, y;

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-this->_w - 10, this->_w + 10, -this->_h - 10, this->_h + 10, -120.0, 120.0);

    glLineWidth(1.0);
    glColor3f(0.65, 0.16, 0.16);

    for (int i = 0; i < cut->size(); i++) {
        for (int j = 0; j < cut->get(i).size(); j++) {
            glBegin(GL_LINE_STRIP);
            for (int k = 0; k < cut->get(i).get(j).size(); k++) {
                x = cut->get(i).get(j)[k].getX();
                y = cut->get(i).get(j).get(k).getY();
                glVertex3f(x - this->_x, y - this->_y, i * this->_gap);
            }
            glEnd();
        }
    }
}

void GL::resizeGL(int w, int h) {
    glViewport(0, 0, (GLint)w, (GLint)h);
}
