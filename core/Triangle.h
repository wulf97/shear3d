#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vertices.h"

class Triangle {
public:
    Triangle();
    Triangle(Vertices3f, Vertices3f, Vertices3f);
    Triangle(const Triangle&);
    ~Triangle();

    Vertices3f get(int);
    Tcor minZ();
    Tcor maxZ();
    void print();
private:
    Vertices3f v[3];
};

#endif // TRIANGLE_H
