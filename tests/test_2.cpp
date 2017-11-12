#include "test_2.h"

void test_2() {
    Vertices3f v1(0, 0, 1);
    Vertices3f v2(0, 0, 10);
    Vertices3f v3(5, 0, 10);

    Triangle t(v1, v2, v3);

    Tcor cor = 0.5;
    Cut cutt(t, cor);
    std::vector<Line*> l = cutt.get();

    qDebug() << l.size();
    for (int i = 0; i < l.size(); i++) {
        qDebug() << "#" << i;
        l[i]->print();
    }
}
