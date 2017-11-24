#ifndef CUT_H
#define CUT_H

#include <vector>
#include <cmath>
#include "Triangle.h"
#include "Line.h"
#include "Polyline.h"
#include "Stl.h"
#include "Slice.h"

class Cut {
public:
    Cut(Stl*, Tcor);
    ~Cut();

    Slice get(int);
    int size();
private:
    Line cutTriangle(Triangle, Tcor);
    Vertices2f cutEdge(Vertices3f, Vertices3f, Tcor);
    Tcor cutXZ(Vertices3f, Vertices3f, Tcor);
    Tcor cutYZ(Vertices3f, Vertices3f, Tcor);

    std::vector<Slice> _slice;
};

#endif // CUT_H
