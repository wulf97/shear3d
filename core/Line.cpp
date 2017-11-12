#include "Line.h"

Line::Line() {
    this->level = 0;
    for (int i = 0; i < 2; i++) {
        this->v[i] = Vertices2f();
    }
}

Line::Line(Vertices2f v1, Vertices2f v2, Tcor level) {
    this->level = 0;
    this->v[0] = v1;
    this->v[1] = v2;
}

Line::~Line() {

}

void Line::print() {
    for (int i = 0; i < 2; i++) {
        this->v[i].print();
    }
}
