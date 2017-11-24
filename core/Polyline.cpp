#include "Polyline.h"

Polyline::Polyline() {

}

Polyline::Polyline(const Polyline &pLine) {
    for (int i = 0; i < pLine.v.size(); i++) {
        this->v.push_back(pLine.v[i]);
    }
}

Polyline::~Polyline() {

}

void Polyline::operator = (const Polyline &pLine) {
    this->v = pLine.v;
}

Vertices2f Polyline::operator [] (int i) {
    return this->v.at(i);
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

void Polyline::insert(int i, Vertices2f _v) {
    this->v.insert(this->v.begin() + i, _v);
}

void Polyline::remove(int i) {
    this->v.erase(v.begin() + i);
}

void Polyline::clear() {
    this->v.clear();
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
