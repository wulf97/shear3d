#ifndef GL_H
#define GL_H

#include <vector>
#include <QGLWidget>
#include "Polyline.h"
#include "Stl.h"
#include "Cut.h"

class GL : public QGLWidget {
public:
    GL(Cut*, Tcor, Tcor, Tcor, Tcor, Tcor);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int, int);
private:
    Cut *cut;
    Tcor _gap;
    Tcor _x;
    Tcor _y;
    Tcor _w;
    Tcor _h;
};

#endif // GL_H
