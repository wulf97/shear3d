#include "Vertices.h"

/* Vertices2f */
Vertices2f::Vertices2f(const Vertices2f &v) {
    this->x = v.x;
    this->y = v.y;
}

Vertices2f::~Vertices2f() {

}

void Vertices2f::operator = (Vertices2f v) {
    this->x = v.x;
    this->y = v.y;
}

bool Vertices2f::operator == (Vertices2f v) {
    if (this->x == v.x && this->y == v.y)
        return true;
    return false;

}

bool Vertices2f::operator != (Vertices2f v) {
    if (this->x != v.x || this->y != v.y)
        return true;
    return false;
}

void Vertices2f::set(Tcor x, Tcor y) {
    this->x = x;
    this->y = y;
}

Tcor Vertices2f::getX() {
    return this->x;
}

Tcor Vertices2f::getY() {
    return this->y;
}

void Vertices2f::print() {
    qDebug() << "[" << this->x << ", " << this->y << "]";
}


/* Vertices3f */
Vertices3f::Vertices3f(const Vertices3f &v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

Vertices3f::~Vertices3f() {

}

void Vertices3f::operator = (Vertices3f v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

bool Vertices3f::operator == (Vertices3f v) {
    if (this->x == v.x && this->y == v.y && this->z == v.z)
        return true;
    return false;
}

bool Vertices3f::operator != (Vertices3f v) {
    if (this->x != v.x || this->y != v.y || this->z != v.z)
        return true;
    return false;
}

void Vertices3f::set(Tcor x, Tcor y, Tcor z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Tcor Vertices3f::getX() {
    return this->x;
}

Tcor Vertices3f::getY() {
    return this->y;
}

Tcor Vertices3f::getZ() {
    return this->z;
}

Vertices2f Vertices3f::to2f() {
    return Vertices2f(this->x, this->y);
}

void Vertices3f::print() {
    qDebug() << "[" << this->x << ", " << this->y << ", " << this->z << "]";
}
