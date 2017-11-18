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

    this->sort();
}

Triangle::Triangle(const Triangle &t) {
    for (int i = 0; i < 3; i++) {
        this->v[i] = t.v[i];
    }

    this->sort();
}

Triangle::~Triangle() {

}

Vertices3f Triangle::get(int i) {
    return (i >= 0 && i < 3) ? v[i] : NULL;
}

Tcor Triangle::minZ() {
    return this->v[0].getZ();
}

Tcor Triangle::maxZ() {
    return this->v[2].getZ();
}

void Triangle::print() {
    for (int i = 0; i < 3; i++) {
        this->v[i].print();
    }
}

void Triangle::sort() {
    for (int i = 3; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (v[j].getZ() > v[j + 1].getZ())
                std::swap(v[j], v[j + 1]);
        }
    }
}
