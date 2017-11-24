#include "Triangle.h"

Triangle::Triangle() {
    for (int i = 0; i < 3; i++)
        this->_v[i] = Vertices3f();

    this->_minX = 0;
    this->_maxX = 0;

    this->_minY = 0;
    this->_maxY = 0;

    this->_minZ = 0;
    this->_maxZ = 0;
}

Triangle::Triangle(const Vertices3f &v1, const Vertices3f &v2, const Vertices3f &v3) {
    this->_v[0] = v1;
    this->_v[1] = v2;
    this->_v[2] = v3;

    this->sort();
    this->initMinAndMax();
}

Triangle::Triangle(const Triangle &t) {
    for (int i = 0; i < 3; i++)
        this->_v[i] = t._v[i];

    this->sort();
    this->initMinAndMax();
}

Triangle::~Triangle() {

}

Vertices3f Triangle::get(int i) {
    return this->_v[i];
}

Tcor Triangle::minX() {
    return this->_minX;
}

Tcor Triangle::maxX() {
    return this->_maxX;
}

Tcor Triangle::minY() {
    return this->_minY;
}

Tcor Triangle::maxY() {
    return this->_maxY;
}

Tcor Triangle::minZ() {
    return this->_minZ;
}

Tcor Triangle::maxZ() {
    return this->_maxZ;
}

void Triangle::print() {
    qDebug() << "Triangle:";
    for (int i = 0; i < 3; i++) {
        this->_v[i].print();
    }
}

void Triangle::initMinAndMax() {
    Vertices3f v1, v2, v3;

    v1 = this->_v[0];
    v2 = this->_v[1];
    v3 = this->_v[2];

    this->_minX = v1.getX();
    if (v2.getX() < this->_minX)
        this->_minX = v2.getX();
    else
        if (v3.getX() < this->_minX)
            this->_minX = v3.getX();

    this->_maxX = v1.getX();
    if (v2.getX() > this->_maxX)
        this->_maxX = v2.getX();
    else
        if (v3.getX() > this->_maxX)
            this->_maxX = v3.getX();

    this->_minY = v1.getY();
    if (v2.getY() < this->_minY)
        this->_minY = v2.getY();
    else
        if (v3.getY() < this->_minY)
            this->_minY = v3.getY();

    this->_maxY = v1.getY();
    if (v2.getY() > this->_maxY)
        this->_maxY = v2.getY();
    else
        if (v3.getY() > this->_maxY)
            this->_maxY = v3.getY();

    this->_minZ = this->_v[0].getZ();
    this->_maxZ = this->_v[2].getZ();
}

void Triangle::sort() {
    for (int i = 3; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (this->_v[j].getZ() > this->_v[j + 1].getZ())
                std::swap(this->_v[j], this->_v[j + 1]);
        }
    }
}
