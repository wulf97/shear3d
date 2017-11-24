#ifndef STL_H
#define STL_H

#include <vector>
#include <fstream>

#include "Vertices.h"
#include "Triangle.h"

class Stl {
public:
    Stl(const char*);
    ~Stl();

    Triangle get(int);
    int size();
    Tcor minX();
    Tcor maxX();
    Tcor minY();
    Tcor maxY();
    Tcor minZ();
    Tcor maxZ();
private:
    void print();

    int _size;
    Tcor _minX;
    Tcor _maxX;
    Tcor _minY;
    Tcor _maxY;
    Tcor _minZ;
    Tcor _maxZ;
    std::vector<Triangle> _buff;
};

#endif // STL_H
