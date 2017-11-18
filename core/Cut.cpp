#include "Cut.h"

Cut::Cut(Stl *stl, Tcor zCor, Polyline &pLine) {
    std::vector<Line> lineSet;
    Line line;
    //Polyline pLine;

    for (int i = 0; stl->get(i).minZ() <= zCor; i++) {
        if (stl->get(i).maxZ() >= zCor) {
            if (stl->get(i).get(0).getZ() != zCor || stl->get(i).get(1).getZ() != zCor || stl->get(i).get(2).getZ() != zCor) {
                line = this->cutTriangle(stl->get(i), zCor);
                if (line.begin() != line.end())
                    lineSet.push_back(line);
            }
        }
    }

    while (pLine.empty() || pLine.begin() != pLine.end()) {
        for (int i = 0; i < lineSet.size(); i++) {
            if (!pLine.empty()) {
                if (pLine.end() == lineSet[i].begin()) {
                    pLine.addEnd(lineSet[i].end());
                    lineSet.erase(lineSet.begin() + i);
                    i = 0;
                } else {
                    if (pLine.end() == lineSet[i].end()) {
                        pLine.addEnd(lineSet[i].begin());
                        lineSet.erase(lineSet.begin() + i);
                        i = 0;
                    }
                }
            } else {
                pLine.addEnd(lineSet[i].begin());
                pLine.addEnd(lineSet[i].end());
                lineSet.erase(lineSet.begin() + i);
                i = 0;
            }
        }
    }

}

Cut::~Cut() {

}

Line Cut::cutTriangle(Triangle t, Tcor zCor) {
    Vertices2f v1, v2;

    if (t.get(0).getZ() == zCor && t.get(1).getZ() == zCor)
        return Line(t.get(0).to2f(), t.get(1).to2f());

    if (t.get(0).getZ() == zCor && t.get(2).getZ() == zCor)
        return Line(t.get(0).to2f(), t.get(2).to2f());

    if (t.get(1).getZ() == zCor && t.get(2).getZ() == zCor)
        return Line(t.get(1).to2f(), t.get(2).to2f());

    if (t.get(0).getZ() <= zCor && t.get(1).getZ() <= zCor) {
        v1 = this->cutEdge(t.get(0), t.get(2), zCor);
        v2 = this->cutEdge(t.get(1), t.get(2), zCor);
    } else {
        if (t.get(0).getZ() <= zCor) {
            v1 = this->cutEdge(t.get(0), t.get(1), zCor);
            v2 = this->cutEdge(t.get(0), t.get(2), zCor);
        }
    }

    return Line(v1, v2);
}

Vertices2f Cut::cutEdge(Vertices3f v1, Vertices3f v2, Tcor zCor) {
    Tcor x = this->cutXZ(v1, v2, zCor);
    Tcor y = this->cutYZ(v1, v2, zCor);

    return Vertices2f(x, y);
}

Tcor Cut::cutXZ(Vertices3f v1, Vertices3f v2, Tcor zCor) {
    return (v2.getX() - v1.getX()) * (zCor - v1.getZ()) / (v2.getZ() - v1.getZ()) + v1.getX();
}

Tcor Cut::cutYZ(Vertices3f v1, Vertices3f v2, Tcor zCor) {
    return (v2.getY() - v1.getY()) * (zCor - v1.getZ()) / (v2.getZ() - v1.getZ()) + v1.getY();
}
