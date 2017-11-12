#include "Stl.h"

Stl::Stl(const char *str) {
    this->_patch = str;
    this->_flag = NULL;
    this->_index = 0;
    this->_buffSize = 0;
}

Stl::~Stl() {

}

void Stl::read() {
    std::ifstream file;
    Triangle t;

    file.open(this->_patch, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        if (this->_flag == NULL) {
            file.seekg(80, std::ios::beg);
            file.read((char*)&this->_size, sizeof(this->_size));
            this->_flag = 1;
        }

        this->_buffSize = ((this->_size - this->_index) > BUFF_SIZE)? BUFF_SIZE: this->_size - this->_index;
        this->_buff.reserve(this->_buffSize);
        for (int i = 0; i < this->_buffSize; i++) {
            file.seekg(12, std::ios::cur);
            file.read((char*)&t, sizeof(t));
            this->_buff.push_back(t);
            file.seekg(2, std::ios::cur);

            this->_index++;
        }

        file.close();
    };
}

Triangle Stl::get(int i) {
    return this->_buff.at(i);
}

bool Stl::end() {
    if (this->_size == this->_index && this->_flag != NULL)
        return true;
    else
        return false;
}

int Stl::size() {
    return _buffSize;
}
