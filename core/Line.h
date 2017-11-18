#ifndef LINE_H
#define LINE_H

#include "Vertices.h"

class Line {
public:
    Line();
    Line(Vertices2f, Vertices2f);
    ~Line();

    Vertices2f get(int);
    Vertices2f end();
    Vertices2f begin();
    void print();
private:
    Vertices2f v[2];
};

#endif // LINE_H
