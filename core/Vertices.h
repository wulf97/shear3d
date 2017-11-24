#ifndef VERTIX_H
#define VERTIX_H

#include <iostream>
#include <vector>
#include <QDebug>

typedef float Tcor;

class Vertices2f {
public:
    Vertices2f(Tcor x = 0, Tcor y = 0) : _x(x), _y(y) {}
    Vertices2f(const Vertices2f&);
    ~Vertices2f();

    void operator = (const Vertices2f&);
    bool operator == (const Vertices2f&);
    bool operator != (const Vertices2f&);

    void set(Tcor, Tcor);
    Tcor getX();
    Tcor getY();

    void print();
private:
    Tcor _x;
    Tcor _y;
};

class Vertices3f {
public:
    Vertices3f(Tcor x = 0, Tcor y = 0, Tcor z = 0) : _x(x), _y(y), _z(z) {}
    Vertices3f(const Vertices3f&);
    ~Vertices3f();

    void operator = (const Vertices3f&);
    bool operator == (const Vertices3f&);
    bool operator != (const Vertices3f&);

    void set(Tcor, Tcor, Tcor);
    Tcor getX();
    Tcor getY();
    Tcor getZ();
    Vertices2f to2f();
    void print();
private:
    Tcor _x;
    Tcor _y;
    Tcor _z;
};

#endif // VERTIX_H
