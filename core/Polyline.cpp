#include "Polyline.h"

Polyline::Polyline() {
}

Polyline::~Polyline() {

}

void Polyline::operator = (Polyline pLine) {
    this->v = pLine.v;
}

void Polyline::addEnd(Vertices2f v) {
    this->v.push_back(v);
}

void Polyline::addBegin(Vertices2f v) {
    this->v.insert(this->v.begin(), v);
}

Vertices2f Polyline::get(int i) {
    return this->v[i];
}

Vertices2f Polyline::end() {
    return this->v.back();
}

Vertices2f Polyline::begin() {
    return this->v.front();
}

bool Polyline::empty() {
    if (this->v.size() == 0)
        return true;
    else
        return false;
}

int Polyline::size() {
    return this->v.size();
}

void Polyline::print() {
    qDebug() << "Polyline:";
    for (int i = 0; i < this->v.size(); i++) {
        this->v[i].print();
    }
}
