#include <QApplication>
#include "MainWindow.h"
#include "Test.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    Test *t = new Test();
    t->init();

    return a.exec();
}