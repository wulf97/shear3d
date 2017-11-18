#include "Line.h"

Line::Line() {
    for (int i = 0; i < 2; i++) {
        this->v[i] = Vertices2f();
    }
}

Line::Line(Vertices2f v1, Vertices2f v2) {
    this->v[0] = v1;
    this->v[1] = v2;
}

Line::~Line() {

}

Vertices2f Line::get(int i) {
    return this->v[i];
}

Vertices2f Line::end() {
    return this->v[1];
}

Vertices2f Line::begin() {
    return this->v[0];
}

void Line::print() {
    qDebug() << "Line:";
    for (int i = 0; i < 2; i++) {
        this->v[i].print();
    }
}
