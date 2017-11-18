#include "Stl.h"

Stl::Stl(const char *patch) {
    std::ifstream file;
    Triangle t;
    int size;

    file.open(patch, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        file.seekg(80, std::ios::beg);
        file.read((char*)&size, sizeof(size));
        this->_size = size;

        this->_buff.reserve(size);
        for (int i = 0; i < size; i++) {
            file.seekg(12, std::ios::cur);
            file.read((char*)&t, sizeof(t));
            this->_buff.push_back(t);
            file.seekg(2, std::ios::cur);
        }

        file.close();
    }

    this->sort();
}

Stl::~Stl() {

}

Triangle Stl::get(int i) {
    return this->_buff[i];
}

int Stl::size() {
    return this->_size;
}

void Stl::sort() {
    for (int i = this->_size; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (this->_buff[j].minZ() > this->_buff[j + 1].minZ())
                std::swap(this->_buff[j], this->_buff[j + 1]);
        }
    }
}
