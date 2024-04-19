#include "mainwindow.h"
#include "mainoperation.h"
#include "logs.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
