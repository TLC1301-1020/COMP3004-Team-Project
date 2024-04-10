#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create menu tree
    operationMenu = new Menu("",{"NEW SESSION","SESSION LOG","TIME AND DATE"}, nullptr);
    operationMenuOG = operationMenu;
    initializeMainMenu(operationMenu);

    // Initialize the main menu view
    activeQListWidget = ui->mainMenuListView;
    activeQListWidget->addItems(operationMenu->getMenuItems());
    activeQListWidget->setCurrentRow(0);

    //Initialize the main operation
    mOp = new MainOperation();

    connect(ui->Button_Menu, &QPushButton::pressed, this, &MainWindow::navigateToMainMenu);
    connect(ui->Button_Direction_Up, &QPushButton::pressed, this, &MainWindow::navigateUpMenu);
    connect(ui->Button_Direction_Down, &QPushButton::pressed, this, &MainWindow::navigateDownMenu);
    connect(ui->Button_Start, &QPushButton::pressed, this, &MainWindow::playButton);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mOp;
}

//initialize funciton
void MainWindow::initializeMainMenu(Menu* m) {

    QStringList frequenciesList;
    QStringList programsList;


    Menu* programs = new Menu("PROGRAMS", {"a"}, m);
    Menu* frequencies = new Menu("FREQUENCIES", {"b"}, m);
    Menu* history = new Menu("HISTORY", {"c"}, m);

    m->addChildMenu(programs);
    m->addChildMenu(frequencies);
    m->addChildMenu(history);
}

void MainWindow::newSession() {
    mOp->addToLogs("\n\nNew Test\n");

    mOp->EEGAverage(1);
    mOp->EEGTreatment(1);
    mOp->EEGAverage(1);

    cout << mOp->getLogs() << endl;
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

void MainWindow::playButton() {
    int index = activeQListWidget->currentRow() + 1;

    switch(index){
        case 1:
            cout << "Starting main operation..." << endl;
            ui->programViewWidget->setVisible(true);
            newSession();
        break;

        case 2:
            cout << "Opening logs..." << endl;
            ui->programViewWidget->setVisible(true);

        break;

        case 3:
            cout << "Time and Date..." << endl;
            ui->programViewWidget->setVisible(true);
        break;
    }
}

