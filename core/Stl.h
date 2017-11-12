#ifndef STL_H
#define STL_H

#include <vector>
#include <fstream>

#include "Triangle.h"

#define BUFF_SIZE 512

class Stl {
public:
    Stl(const char*);
    ~Stl();

    void read();
    Triangle get(int);
    bool end();
    int size();
private:
    const char *_patch;
    char _flag;
    int _size;
    int _buffSize;
    int _index;
    std::vector<Triangle> _buff;
};

#endif // STL_H
