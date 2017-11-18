#ifndef CUT_H
#define CUT_H

#include <cmath>
#include "Triangle.h"
#include "Line.h"
#include "Polyline.h"
#include "Stl.h"

class Cut {
public:
    Cut(Stl*, Tcor, Polyline&);
    ~Cut();
private:
    Line cutTriangle(Triangle, Tcor);
    Vertices2f cutEdge(Vertices3f, Vertices3f, Tcor);
    Tcor cutXZ(Vertices3f, Vertices3f, Tcor);
    Tcor cutYZ(Vertices3f, Vertices3f, Tcor);

    std::vector<Polyline*> pLine;
};

#endif // CUT_H
