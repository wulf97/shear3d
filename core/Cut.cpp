#include "Cut.h"

Cut::Cut(Triangle t, Tcor gap) {
    Tcor min = t.minZ();
    Tcor max = t.maxZ();
    Tcor level = min;
    Vertices2f v1, v2;

    if (t.minZ() != t.maxZ()) {

        /*if (t.minZ() - floor(t.minZ()/gap) < 0.000001) {
            if (t.get(0).getZ() == min && t.get(1).getZ() == min)
                this->line.push_back(new Line(t.get(0).to2f(), t.get(1).to2f(), level));
            else
                if (t.get(0).getZ() == min && t.get(2).getZ() == min)
                    this->line.push_back(new Line(t.get(0).to2f(), t.get(2).to2f(), level));
                else
                    if (t.get(1).getZ() == min && t.get(2).getZ() == min)
                        this->line.push_back(new Line(t.get(1).to2f(), t.get(2).to2f(), level));
                level += gap;
        }*/

        while (level <= max) {
            if (t.get(0).getZ() < level) {
                v1 = this->cutEdge(t.get(0), t.get(1), level);
                v2 = this->cutEdge(t.get(0), t.get(2), level);
            } else {
                if (t.get(1).getZ() < level) {
                    v1 = this->cutEdge(t.get(1), t.get(0), level);
                    v2 = this->cutEdge(t.get(1), t.get(2), level);
                } else {
                    if (t.get(2).getZ() < level) {
                        v1 = this->cutEdge(t.get(2), t.get(1), level);
                        v2 = this->cutEdge(t.get(2), t.get(0), level);
                    }
                }
            }

            this->line.push_back(new Line(v1, v2, level));
            level += gap;
        }
    }
}

Cut::~Cut() {

}

std::vector<Line*> Cut::get() {
    return this->line;
}

Vertices2f Cut::cutEdge(Vertices3f v1, Vertices3f v2, Tcor level) {
    Tcor x = this->cutXZ(v1, v2, level);
    Tcor y = this->cutYZ(v1, v2, level);

    return Vertices2f(x, y);
}

Tcor Cut::cutXZ(Vertices3f v1, Vertices3f v2, Tcor level) {
    return (v2.getX() - v1.getX()) * (level - v1.getZ()) / (v2.getZ() - v1.getZ()) + v1.getX();
}

Tcor Cut::cutYZ(Vertices3f v1, Vertices3f v2, Tcor level) {
    return (v2.getY() - v1.getY()) * (level - v1.getZ()) / (v2.getZ() - v1.getZ()) + v1.getY();
}
