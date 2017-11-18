#ifndef GL_H
#define GL_H

#include <vector>
#include <QGLWidget>
#include "Polyline.h"
#include "Stl.h"
#include "Cut.h"

class GL : public QGLWidget {
public:
    GL();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int, int);
private:
    ///std::vector<Polyline> pLine;
    Polyline pLine[10];
};

#endif // GL_H
