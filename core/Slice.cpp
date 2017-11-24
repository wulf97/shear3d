#include "Slice.h"

Slice::Slice() {

}

void Slice::add(Polyline pLine) {
    this->_pLine.push_back(pLine);
}

Polyline Slice::get(int i) {
    return this->_pLine[i];
}

void Slice::clear() {
    this->_pLine.clear();
}

int Slice::size() {
    return this->_pLine.size();
}
