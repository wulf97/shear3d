#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vertices.h"

class Triangle {
public:
    Triangle();
    Triangle(const Vertices3f&, const Vertices3f&, const Vertices3f&);
    Triangle(const Triangle&);
    ~Triangle();

    Vertices3f get(int);
    Tcor minX();
    Tcor maxX();
    Tcor minY();
    Tcor maxY();
    Tcor minZ();
    Tcor maxZ();
    void print();
private:
    void initMinAndMax();
    void sort();

    Vertices3f _v[3];

    Tcor _minX;
    Tcor _maxX;
    Tcor _minY;
    Tcor _maxY;
    Tcor _minZ;
    Tcor _maxZ;
};

#endif // TRIANGLE_H
