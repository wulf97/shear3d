#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "Line.h"
#include "Polyline.h"

class Slice {
public:
    Slice();

    void add();
private:
    std::vector<Polyline> pLine;
};

#endif // LEVEL_H
