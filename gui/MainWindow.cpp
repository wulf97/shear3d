#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

}

MainWindow::~MainWindow() {

}

void MainWindow::initPatch(char **patch) {
    Tcor gap = 2.1;
    Tcor x, y, w, h;

    Stl *stl = new Stl(patch[1]);
    gap = std::stof(patch[2]);

    //Stl *stl = new Stl("/home/alexej/Desktop/cube.stl");
    //Stl *stl = new Stl("/home/alexej/Downloads/natyagitel.stl");
    //Stl *stl = new Stl("/home/alexej/Desktop/2.stl");
    //Stl *stl = new Stl("/home/alexej/Desktop/yoda.stl");
    Cut *cut = new Cut(stl, gap);

    w = stl->maxX() - stl->minX();
    h = stl->maxY() - stl->minY();
    x = stl->minX() + w / 2;
    y = stl->minY() + h / 2;

    stl->~Stl();
    GL *gl = new GL(cut, gap, x, y, w, h);
    resize(900, 700);
    setCentralWidget(gl);
}
