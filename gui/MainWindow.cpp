#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

}

MainWindow::~MainWindow() {

}

void MainWindow::initPatch(char **patch) {
    Tcor gap = 2.1;
    Tcor x, y, z, w, h, d;

    //Stl *stl = new Stl(patch[1]);
    //gap = std::stof(patch[2]);

    //Stl *stl = new Stl("/home/alexej/Desktop/cube.stl");
    Stl *stl = new Stl("/home/alexej/Downloads/natyagitel.stl");
    //Stl *stl = new Stl("/home/alexej/Downloads/robo.stl");
    //Stl *stl = new Stl("/home/alexej/Desktop/newyoda.stl");
    Cut *cut = new Cut(stl, gap);

    w = stl->maxX() - stl->minX();
    h = stl->maxY() - stl->minY();
    d = stl->maxZ() - stl->minZ();
    x = stl->minX() + w / 2;
    y = stl->minY() + h / 2;
    z = stl->minZ() + d / 2;

    stl->~Stl();
    GL *gl = new GL(cut, gap, x, y, z, w, h, d);
    resize(900, 700);
    setCentralWidget(gl);
}
