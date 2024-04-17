#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widget = new QWidget(this);
    logArea = new QVBoxLayout(this);


    // Create menu tree
    operationMenu = new Menu("",{"NEW SESSION","SESSION LOG","TIME AND DATE"}, nullptr);
    operationMenuOG = operationMenu;
    initializeMainMenu(operationMenu);
    menuState = false;

    // Initialize the main menu view
    activeQListWidget = ui->mainMenuListView;
    activeQListWidget->addItems(operationMenu->getMenuItems());
    activeQListWidget->setCurrentRow(0);
    ui->scrollArea->setVisible(false);

    //Initialize the main operation
    mOp = new MainOperation();

    connect(ui->Button_Menu, &QPushButton::pressed, this, &MainWindow::navigateToMainMenu);
    connect(ui->Button_Direction_Up, &QPushButton::pressed, this, &MainWindow::navigateUpMenu);
    connect(ui->Button_Direction_Down, &QPushButton::pressed, this, &MainWindow::navigateDownMenu);
    connect(ui->Button_Start, &QPushButton::pressed, this, &MainWindow::playButton);
    connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::clickStartButton);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mOp;
    delete logArea;
    delete widget;
    delete operationMenu;
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

    ui->programViewWidget->setVisible(true);

    mOp->addToLogs("\n\nNew Test\n");

    //Get Baseline:
    mOp->EEGBaseline();

    for(int i = 0; i < 21; i++) {
        stringstream newLog;
        newLog << "\nEEG Node " << i+1 << " Treatment:" << "\n";
        mOp->addToLogs(newLog.str());
        mOp->EEGAverage(i);
        mOp->EEGTreatment(i);
        mOp->EEGAverage(i);
    }

    mOp->EEGBaseline();

    changeBatteryLevel(mOp->getBattery() - 10.0);



}

void MainWindow::readLogs() {
    QLayoutItem* tempItem;
    while(logArea->count() != 0) {
        tempItem = logArea->takeAt(0);
        delete tempItem;
    }
    delete logArea;
    delete widget;

    string temp;
    QString qLogs;
    mOp->getLogs();
    widget = new QWidget(this);
    logArea = new QVBoxLayout(widget);
    ifstream in("neuraset_logs.txt", istream::in);
    if(in.is_open()) {
        while(in.good()) {
            getline(in, temp);
            qLogs = QString::fromStdString(temp);
            QLabel* label = new QLabel(this);
            label->setText(qLogs);
            logArea->addWidget(label);

        }
    }
    ui->scrollArea->setWidget(widget);
    in.close();
    //ui->programViewWidget->setVisible(true);
    //ui->List_View->setVisible(false);
    ui->scrollArea->setVisible(true);
}

void MainWindow::updateMenu(const QStringList menuItems) {

    activeQListWidget->clear();
    activeQListWidget->addItems(menuItems);
    activeQListWidget->setCurrentRow(0);

}


// Menu
void MainWindow::navigateToMainMenu(){
    if(mOp->getBattery() > 0.0) {
        qInfo("testMenu");
        updateMenu(operationMenu->getMenuItems());
        ui->programViewWidget->setVisible(false);
        ui->scrollArea->setVisible(false);
        menuState = true;
    }
    else {
        qInfo("Battery depleted");
    }
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
    if(menuState == true) {
        menuState = false;
        int index = activeQListWidget->currentRow() + 1;

        switch(index){
            case 1:
                cout << "Starting main operation..." << endl;
                newSession();
            break;

            case 2:
                cout << "Opening logs..." << endl;
                readLogs();

            break;

            case 3:
                cout << "Time and Date..." << endl;
                ui->programViewWidget->setVisible(true);
            break;
        }

    }
}

// battery
void MainWindow::changeBatteryLevel(double newLevel) {

    if(newLevel < 0.0) {
        newLevel = 0.0;
    }

    if (newLevel >= 0.0 && newLevel <= 100.0) {
        int newLevelInt = int(newLevel);
        ui->batteryLevelBar->setValue(newLevelInt);

        mOp->setBattery(newLevel);

        QString highBatteryHealth = "QProgressBar { selection-background-color: rgb(78, 154, 6); background-color: rgb(0, 0, 0); }";
        QString mediumBatteryHealth = "QProgressBar { selection-background-color: rgb(196, 160, 0); background-color: rgb(0, 0, 0); }";
        QString lowBatteryHealth = "QProgressBar { selection-background-color: rgb(164, 0, 0); background-color: rgb(0, 0, 0); }";

        if (newLevelInt >= 50) {
            ui->batteryLevelBar->setStyleSheet(highBatteryHealth);
        }
        else if (newLevelInt >= 20) {
            ui->batteryLevelBar->setStyleSheet(mediumBatteryHealth);
        }
        else {
            ui->batteryLevelBar->setStyleSheet(lowBatteryHealth);
        }
    }
}

void MainWindow::clickStartButton(){
    changeBatteryLevel(100.00);
}

