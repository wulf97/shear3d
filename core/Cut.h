#ifndef CUT_H
#define CUT_H

#include <cmath>
#include "Triangle.h"
#include "Line.h"

class Cut {
public:
    Cut(Triangle, Tcor);
    ~Cut();

    std::vector<Line*> get();
private:
    Vertices2f cutEdge(Vertices3f, Vertices3f, Tcor);
    Tcor cutXZ(Vertices3f, Vertices3f, Tcor);
    Tcor cutYZ(Vertices3f, Vertices3f, Tcor);

    std::vector<Line*> line;
};

#endif // CUT_H
