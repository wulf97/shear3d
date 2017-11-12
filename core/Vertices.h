#ifndef VERTIX_H
#define VERTIX_H

#include <iostream>
#include <vector>
#include <QDebug>

typedef float Tcor;

class Vertices2f {
public:
    Vertices2f(Tcor _x = 0, Tcor _y = 0) : x(_x), y(_y) {}
    Vertices2f(const Vertices2f&);
    ~Vertices2f();

    void operator = (Vertices2f*);
    bool operator == (Vertices2f*);
    bool operator != (Vertices2f*);

    void set(Tcor, Tcor);
    Tcor getX();
    Tcor getY();

    void print();
private:
    Tcor x;
    Tcor y;
};

class Vertices3f {
public:
    Vertices3f(Tcor _x = 0, Tcor _y = 0, Tcor _z = 0) : x(_x), y(_y), z(_z) {}
    Vertices3f(const Vertices3f&);
    ~Vertices3f();

    void operator = (Vertices3f*);
    bool operator == (Vertices3f*);
    bool operator != (Vertices3f*);

    void set(Tcor, Tcor, Tcor);
    Tcor getX();
    Tcor getY();
    Tcor getZ();
    Vertices2f to2f();
    void print();
private:
    Tcor x;
    Tcor y;
    Tcor z;
};

#endif // VERTIX_H
