#include "GL.h"

GL::GL(Cut *cut, Tcor gap, Tcor x, Tcor y, Tcor z, Tcor w, Tcor h, Tcor d) : QGLWidget() {
    this->_cut = cut;
    this->_gap = gap;
    this->_x = x;
    this->_y = y;
    this->_z = z;
    this->_w = w;
    this->_h = h;
    this->_d = d;
    this->_xrot = 0;
    this->_yrot = 0;
    this->_lMode = ALL_LAYERS_MODE;
    this->_lIterator = 0;

    setFocusPolicy(Qt::StrongFocus);
}

void GL::initializeGL() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    updateGL();
}

void GL::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glRotatef(this->_xrot, 1.0, 0.0, 0.0);
    glRotated(this->_xrot, 1.0, 0.0, 0.0);
    glRotated(this->_yrot, 0.0, 1.0, 0.0);

    glOrtho(-this->_w, this->_w, -this->_h, this->_h, -this->_d, this->_d);

    this->drawFigure();
}

void GL::resizeGL(int w, int h) {
    glViewport(0, 0, (GLint)w, (GLint)h);
}

void GL::keyPressEvent(QKeyEvent *ev) {
    switch (ev->key()) {
        case Qt::Key_Up:
            this->rUp();
        break;
        case Qt::Key_Down:
            this->rDown();
        break;
        case Qt::Key_Left:
            this->rLeft();
        break;
        case Qt::Key_Right:
            this->rRight();
        break;
        case Qt::Key_Space:
            this->switchLayerMode();
        break;
        case Qt::Key_N:
            this->nextLayer();
        break;
        case Qt::Key_B:
            this->beforLayer();
        break;
    }

    updateGL();
}

void GL::drawFigure() {
    Tcor x, y;
    int lAmount;
    int it;

    switch (this->_lMode) {
        case ALL_LAYERS_MODE:
            lAmount = this->_cut->size();
            it = 0;
        break;
        case PARTIAL_LAYERS_MODE:
            lAmount = this->_lIterator + 1;
            it = 0;
        break;
        case ONE_LAYERS_MODE:
            lAmount = this->_lIterator + 1;
            it = this->_lIterator;
        break;
    }

    glLineWidth(1.0);
    glColor3f(0.65, 0.16, 0.16);

    while (it < lAmount) {
        for (int i = 0; i < this->_cut->get(it).size(); i++) {
            glBegin(GL_LINE_STRIP);
            for (int j = 0; j < this->_cut->get(it).get(i).size(); j++) {
                x = this->_cut->get(it).get(i)[j].getX();
                y = this->_cut->get(it).get(i)[j].getY();

                if (it == lAmount - 1)
                    glColor3f(0.0, 0.0, 1.0);

                glVertex3f(x - this->_x, y - this->_y, it * this->_gap - this->_z);
            }
            glEnd();
        }

        it++;
    }
}

void GL::rUp() {
    this->_xrot += 5;
}

void GL::rDown() {
    this->_xrot -= 5;
}

void GL::rLeft() {
    this->_yrot -= 5;
}

void GL::rRight() {
    this->_yrot += 5;
}

void GL::switchLayerMode() {
    switch (this->_lMode) {
        case ALL_LAYERS_MODE:
            this->_lMode = PARTIAL_LAYERS_MODE;
        break;
        case PARTIAL_LAYERS_MODE:
            this->_lMode = ONE_LAYERS_MODE;
        break;
        case ONE_LAYERS_MODE:
            this->_lMode = ALL_LAYERS_MODE;
        break;
    }
}

void GL::nextLayer() {
    if (this->_lMode == PARTIAL_LAYERS_MODE || this->_lMode == ONE_LAYERS_MODE) {
        if (this->_lIterator < this->_cut->size() - 1)
               this->_lIterator++;
    }
}

void GL::beforLayer() {
    if (this->_lMode == PARTIAL_LAYERS_MODE || this->_lMode == ONE_LAYERS_MODE) {
        if (this->_lIterator > 0)
            this->_lIterator--;
    }
}
