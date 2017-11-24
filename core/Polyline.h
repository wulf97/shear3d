#ifndef POLYLINE_H
#define POLYLINE_H

#include "Vertices.h"

class Polyline {
public:
    Polyline();
    Polyline(const Polyline&);
    ~Polyline();

    void operator = (const Polyline&);
    Vertices2f operator [] (int);

    void addEnd(Vertices2f);
    void addBegin(Vertices2f);
    Vertices2f get(int);
    Vertices2f end();
    Vertices2f begin();
    void insert(int, Vertices2f);
    void remove(int);
    void clear();
    bool empty();
    int size();
    void print();
private:
    std::vector<Vertices2f> v;
};

#endif // POLYLINE_H
