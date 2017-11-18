#ifndef STL_H
#define STL_H

#include <vector>
#include <fstream>

#include "Triangle.h"

class Stl {
public:
    Stl(const char*);
    ~Stl();

    Triangle get(int);
    int size();
private:
    void sort();

    int _size;
    std::vector<Triangle> _buff;
};

#endif // STL_H
