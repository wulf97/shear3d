#include "Stl.h"

Stl::Stl(const char *patch) {
    std::ifstream file;
    Vertices3f v1, v2, v3;
    Triangle t;
    bool flag = false;
    int size;
    int count = 0;
    int it;

    file.open(patch, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        file.seekg(80, std::ios::beg);
        file.read((char*)&size, sizeof(size));
        this->_size = size;

        qDebug() << "Size: "<<size;
        this->_buff.reserve(size);
        for (int i = 0; i < size; i++) {
            file.seekg(12, std::ios::cur);

            file.read((char*)&v1, sizeof(Vertices3f));
            file.read((char*)&v2, sizeof(Vertices3f));
            file.read((char*)&v3, sizeof(Vertices3f));

            t = Triangle(v1, v2, v3);

            this->_buff.push_back(t);
            if (i != 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (this->_buff[j + 1].minZ() < this->_buff[j].minZ()) {
                        std::swap(this->_buff[j + 1], this->_buff[j]);
                    } else break;
                }
            }

            file.seekg(2, std::ios::cur);

            if (flag == false) {
                this->_minX = t.minX();
                this->_maxX = t.maxX();
                this->_minY = t.minY();
                this->_maxY = t.maxY();
                this->_minZ = t.minZ();
                this->_maxZ = t.maxZ();
                flag = true;
            } else {
                if (this->_minX > t.minX())
                    this->_minX = t.minX();

                if (this->_maxX < t.maxX())
                    this->_maxX = t.maxX();

                if (this->_minY > t.minY())
                    this->_minY = t.minY();

                if (this->_maxY < t.maxY())
                    this->_maxY = t.maxY();

                if (this->_minZ > t.minZ())
                    this->_minZ = t.minZ();

                if (this->_maxZ < t.maxZ())
                    this->_maxZ = t.maxZ();

            }
        }

        file.close();
    }
}

Stl::~Stl() {
    this->_buff.clear();
}

Triangle Stl::get(int i) {
    return this->_buff[i];
}

int Stl::size() {
    return this->_size;
}

Tcor Stl::minX() {
    return this->_minX;
}

Tcor Stl::maxX() {
    return this->_maxX;
}

Tcor Stl::minY() {
    return this->_minY;
}

Tcor Stl::maxY() {
    return this->_maxY;
}

Tcor Stl::minZ() {
    return this->_minZ;
}

Tcor Stl::maxZ() {
    return this->_maxZ;
}

void Stl::print() {
    qDebug() << "strt";
    for (int i = 0; i < this->_buff.size(); i++)
        qDebug() << this->_buff[i].minZ();
    qDebug() << "end";
}
