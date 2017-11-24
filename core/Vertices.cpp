#include "Vertices.h"

/* Vertices2f */
Vertices2f::Vertices2f(const Vertices2f &v) {
    this->_x = v._x;
    this->_y = v._y;
}

Vertices2f::~Vertices2f() {

}

void Vertices2f::operator = (const Vertices2f &v) {
    this->_x = v._x;
    this->_y = v._y;
}

bool Vertices2f::operator == (const Vertices2f &v) {
    if (this->_x == v._x && this->_y == v._y)
        return true;
    return false;

}

bool Vertices2f::operator != (const Vertices2f &v) {
    if (this->_x != v._x || this->_y != v._y)
        return true;
    return false;
}

void Vertices2f::set(Tcor x, Tcor y) {
    this->_x = x;
    this->_y = y;
}

Tcor Vertices2f::getX() {
    return this->_x;
}

Tcor Vertices2f::getY() {
    return this->_y;
}

void Vertices2f::print() {
    qDebug() << "[" << this->_x << ", " << this->_y << "]";
}


/* Vertices3f */
Vertices3f::Vertices3f(const Vertices3f &v) {
    this->_x = v._x;
    this->_y = v._y;
    this->_z = v._z;
}

Vertices3f::~Vertices3f() {

}

void Vertices3f::operator = (const Vertices3f &v) {
    this->_x = v._x;
    this->_y = v._y;
    this->_z = v._z;
}

bool Vertices3f::operator == (const Vertices3f &v) {
    if (this->_x == v._x && this->_y == v._y && this->_z == v._z)
        return true;
    return false;
}

bool Vertices3f::operator != (const Vertices3f &v) {
    if (this->_x != v._x || this->_y != v._y || this->_z != v._z)
        return true;
    return false;
}

void Vertices3f::set(Tcor x, Tcor y, Tcor z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Tcor Vertices3f::getX() {
    return this->_x;
}

Tcor Vertices3f::getY() {
    return this->_y;
}

Tcor Vertices3f::getZ() {
    return this->_z;
}

Vertices2f Vertices3f::to2f() {
    return Vertices2f(this->_x, this->_y);
}

void Vertices3f::print() {
    qDebug() << "[" << this->_x << ", " << this->_y << ", " << this->_z << "]";
}
