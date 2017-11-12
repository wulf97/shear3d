#include "Triangle.h"

Triangle::Triangle() {
    for (int i = 0; i < 3; i++) {
        this->v[i] = Vertices3f();
    }
}

Triangle::Triangle(Vertices3f v1, Vertices3f v2, Vertices3f v3) {
    this->v[0] = v1;
    this->v[1] = v2;
    this->v[2] = v3;
}

Triangle::Triangle(const Triangle &t) {
    for (int i = 0; i < 3; i++) {
        this->v[i] = t.v[i];
    }
}

Triangle::~Triangle() {

}

Vertices3f Triangle::get(int i) {
    return (i >= 0 && i < 3) ? v[i] : NULL;
}

Tcor Triangle::minZ() {
    Tcor min;

    min = this->v[0].getZ();
    for (int i = 0; i < 3; i++) {
        if (this->v[i].getZ() < min)
            min = this->v[i].getZ();
    }

    return min;
}

Tcor Triangle::maxZ() {
    Tcor max;

    max = this->v[0].getZ();
    for (int i = 0; i < 3; i++) {
        if (this->v[i].getZ() > max)
            max = this->v[i].getZ();
    }

    return max;
}

void Triangle::print() {
    for (int i = 0; i < 3; i++) {
        this->v[i].print();
    }
}
