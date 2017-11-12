#ifndef LINE_H
#define LINE_H

#include "Vertices.h"

class Line {
public:
    Line();
    Line(Vertices2f, Vertices2f, Tcor);
    ~Line();

    void print();
private:
    Tcor level;
    Vertices2f v[2];
};

#endif // LINE_H
