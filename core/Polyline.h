#ifndef POLYLINE_H
#define POLYLINE_H

#include "Line.h"

class Polyline {
public:
    Polyline();
    ~Polyline();

    void operator = (Polyline);
    void addEnd(Vertices2f);
    void addBegin(Vertices2f);
    Vertices2f get(int);
    Vertices2f end();
    Vertices2f begin();
    bool empty();
    int size();
    void print();
private:
    std::vector<Vertices2f> v;
};

#endif // POLYLINE_H
