#include "test_1.h"

void test_1() {
    Stl *stl = new Stl("/home/alexej/Desktop/cube.stl");
    //Stl *stl = new Stl("/home/alexej/Downloads/der.STL");

    /*int j = 0;
    while(!stl->end()) {
        stl->read();
        for (int i = 0; i < stl->size(); i++) {
            qDebug() << "*";
            stl->get(i).print();
            j++;
        }
    }
    qDebug() << "j = " << j;*/


}
