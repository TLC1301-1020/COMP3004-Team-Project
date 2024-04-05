#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Button_Start,SIGNAL(released()),this, SLOT(showInfo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// show Info
void MainWindow::showInfo(){
    qInfo("test");
}
