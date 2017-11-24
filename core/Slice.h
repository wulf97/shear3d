#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "Line.h"
#include "Polyline.h"

class Slice {
public:
    Slice();

    void add(Polyline);
    Polyline get(int);
    void clear();
    int size();
private:
    std::vector<Polyline> _pLine;
};

#endif // LEVEL_H
