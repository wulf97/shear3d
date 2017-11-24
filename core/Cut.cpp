#include "Cut.h"

Cut::Cut(Stl *stl, Tcor gap) {
    std::vector<Line> lineSet;
    Line line;
    Polyline pLine;
    Slice slice;
    Tcor zCor = stl->minZ();
    bool flag;

    int k = 0;
    while (/*k < 10*/zCor + gap < stl->maxZ()) {
        //qDebug() << "*";
        for (int i = 0; stl->get(i).minZ() <= zCor; i++) {
            if (stl->get(i).maxZ() >= zCor) {
                if (stl->get(i).get(0).getZ() != zCor ||
                    stl->get(i).get(1).getZ() != zCor ||
                    stl->get(i).get(2).getZ() != zCor) {

                    line = this->cutTriangle(stl->get(i), zCor);
                    if (line.begin() != line.end())
                        lineSet.push_back(line);
                }
            }
        }

        while (lineSet.size() != 0) {
            while (pLine.empty() || pLine.begin() != pLine.end()) {

                flag = false;
                for (int i = 0; i < lineSet.size(); i++) {
                    if (!pLine.empty()) {
                        if (pLine.end() == lineSet[i].begin()) {
                            pLine.addEnd(lineSet[i].end());
                            lineSet.erase(lineSet.begin() + i);
                            flag = true;
                            i = 0;
                        } else {
                            if (pLine.end() == lineSet[i].end()) {
                                pLine.addEnd(lineSet[i].begin());
                                lineSet.erase(lineSet.begin() + i);
                                flag = true;
                                i = 0;
                            }
                        }
                    } else {
                        pLine.addEnd(lineSet[i].begin());
                        pLine.addEnd(lineSet[i].end());
                        lineSet.erase(lineSet.begin() + i);
                        flag = true;
                        i = 0;
                    }
                }


                /*if (!flag) {
                    //qDebug() << "*";
                    for (int i = 0; i < slice.size(); i++) {
                        slice.get(i).print();
                        //qDebug() << "*";
                        for (int j = 0; j < slice.get(i).size(); j++) {
                            //qDebug() << "*";
                            //slice.get(i).get(j).print();
                            //pLine.begin().print();
                            //qDebug() << "*";
                            if (slice.get(i).get(j) == pLine.begin()) {
                                qDebug() << "*";
                                for (int k = 0; slice.get(i).get(j + k + 1) != pLine.end(); k++) {
                                    slice.get(i).remove(j + k + 1);
                                    slice.get(i).insert(j + k + 1, pLine.get(k + 1));
                                }
                            }
                        }
                    }
                }*/
            }

            slice.add(pLine);
            pLine.clear();
        }

        this->_slice.push_back(slice);
        slice.clear();
        lineSet.clear();

        zCor += gap;
        k++;
    }
}

Cut::~Cut() {

}

Slice Cut::get(int i) {
    return this->_slice[i];
}

int Cut::size() {
    return this->_slice.size();
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
