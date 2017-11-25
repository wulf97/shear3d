#ifndef GL_H
#define GL_H

#include <vector>
#include <QGLWidget>
#include <QKeyEvent>
#include "Polyline.h"
#include "Stl.h"
#include "Cut.h"

#define ALL_LAYERS_MODE 0
#define PARTIAL_LAYERS_MODE 1
#define ONE_LAYERS_MODE 2

typedef float Tangle;

class GL : public QGLWidget {
public:
    GL(Cut*, Tcor, Tcor, Tcor, Tcor, Tcor, Tcor, Tcor);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int, int);
    void keyPressEvent(QKeyEvent*);
private:
    void drawFigure();
    void rUp();
    void rDown();
    void rLeft();
    void rRight();
    void switchLayerMode();
    void nextLayer();
    void beforLayer();

    Cut *_cut;
    Tcor _gap;
    Tcor _x;
    Tcor _y;
    Tcor _z;
    Tcor _w;
    Tcor _h;
    Tcor _d;
    Tangle _xrot;
    Tangle _yrot;
    int _lMode;
    int _lIterator;
};

#endif // GL_H
