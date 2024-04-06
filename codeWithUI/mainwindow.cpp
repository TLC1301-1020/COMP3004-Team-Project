#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create menu tree
    operationMenu = new MainOperation("",{"NEW SESSION","SESSION LOG","TIME AND DATE"}, nullptr);
    operationMenuOG = operationMenu;
    initializeMainMenu(operationMenu);

    // Initialize the main menu view
    activeQListWidget = ui->mainMenuListView;
    activeQListWidget->addItems(operationMenu->getMenuItems());
    activeQListWidget->setCurrentRow(0);

    connect(ui->Button_Menu, &QPushButton::pressed, this, &MainWindow::navigateToMainMenu);
    connect(ui->Button_Direction_Up, &QPushButton::pressed, this, &MainWindow::navigateUpMenu);
    connect(ui->Button_Direction_Down, &QPushButton::pressed, this, &MainWindow::navigateDownMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//initialize funciton
void MainWindow::initializeMainMenu(MainOperation* m) {

    QStringList frequenciesList;
    QStringList programsList;


    MainOperation* programs = new MainOperation("PROGRAMS", {"a"}, m);
    MainOperation* frequencies = new MainOperation("FREQUENCIES", {"b"}, m);
    MainOperation* history = new MainOperation("HISTORY", {"c"}, m);

    m->addChildMenu(programs);
    m->addChildMenu(frequencies);
    m->addChildMenu(history);
}

void MainWindow::updateMenu(const QStringList menuItems) {

    activeQListWidget->clear();
    activeQListWidget->addItems(menuItems);
    activeQListWidget->setCurrentRow(0);

}


// Menu
void MainWindow::navigateToMainMenu(){
    qInfo("testMenu");
    updateMenu(operationMenu->getMenuItems());
    ui->programViewWidget->setVisible(false);

}

void MainWindow::navigateUpMenu() {

    int nextIndex = activeQListWidget->currentRow() - 1;

    if (nextIndex < 0) {
        nextIndex = activeQListWidget->count() - 1;
    }

    activeQListWidget->setCurrentRow(nextIndex);
}


void MainWindow::navigateDownMenu() {

    int nextIndex = activeQListWidget->currentRow() + 1;

    if (nextIndex > activeQListWidget->count() - 1) {
        nextIndex = 0;
    }

    activeQListWidget->setCurrentRow(nextIndex);
}

