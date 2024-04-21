#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widget = new QWidget(this);
    logArea = new QVBoxLayout(this);

    // Initialize timer counter
    currentTimerCount = -1;

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
    connect(ui->Button_Pause, &QPushButton::pressed, this, &MainWindow::clickPauseButton);
    connect(ui->Button_Stop, &QPushButton::pressed, this, &MainWindow::clickStopButton);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mOp;
    delete logArea;
    delete widget;
    delete operationMenu;
}

//initialize funciton (menu)
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



// click power Button
void MainWindow::clickStartButton(){
    if(mOp->getPowerStatu() == false){
        QString contact = "QPushButton {background-color: rgb(26, 95, 180);}";
        ui->Light_Blue->setStyleSheet(contact);
        QString treatment = "QPushButton {background-color: rgb(38, 162, 105);}";
        ui->Light_Green->setStyleSheet(treatment);
        QString discontact = "QPushButton {background-color: rgb(165, 29, 45);}";
        ui->Light_Red->setStyleSheet(discontact);
        changeBatteryLevel(100.00);
        mOp->setPowerStatu(true);
    }else{
       QString contact = "QPushButton {background-color: rgb(153, 193, 241);}";
        ui->Light_Blue->setStyleSheet(contact);
        QString treatment = "QPushButton {background-color: rgb(143, 240, 164);}";
        ui->Light_Green->setStyleSheet(treatment);
        QString discontact = "QPushButton {background-color: rgb(246, 97, 81);}";
        ui->Light_Red->setStyleSheet(discontact);
        ui->programViewWidget->setVisible(true);
        mOp->setPowerStatu(false);
    }

}



// update menu information
void MainWindow::updateMenu(const QStringList menuItems) {

    activeQListWidget->clear();
    activeQListWidget->addItems(menuItems);
    activeQListWidget->setCurrentRow(0);

}


//Menu (if no power, system close)
void MainWindow::navigateToMainMenu(){
    if(mOp->getBattery() > 0.0) {
        qInfo("testMenu");
        updateMenu(operationMenu->getMenuItems());
        ui->programViewWidget->setVisible(false);
        ui->scrollArea->setVisible(false);
        ui->mainMenuListView->setVisible(true);
        menuState = true;
        t->stop();
    }
    else {
        qInfo("Battery depleted");
    }
}



// navigate up
void MainWindow::navigateUpMenu() {

    int nextIndex = activeQListWidget->currentRow() - 1;

    if (nextIndex < 0) {
        nextIndex = activeQListWidget->count() - 1;
    }

    activeQListWidget->setCurrentRow(nextIndex);
}

// navigate down
void MainWindow::navigateDownMenu() {

    int nextIndex = activeQListWidget->currentRow() + 1;

    if (nextIndex > activeQListWidget->count() - 1) {
        nextIndex = 0;
    }

    activeQListWidget->setCurrentRow(nextIndex);
}



// Battery
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



// timer operate
// initialize timer
void MainWindow::initializeTimer(QTimer* t) {

    currentTimerCount = 1260;

    connect(t, &QTimer::timeout, this, &MainWindow::updateTimer);

    t->start(1000);

}

// updateTimer
void MainWindow::updateTimer() {

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->List_View->setScene(scene);

    if(currentTimerCount > 0){
        timeString = QString::number(currentTimerCount/60) + ":00";
        scene->addText(timeString);
        ui->scrollArea->setVisible(true);
        currentTimerCount = currentTimerCount - 60;
    }else{
        qInfo("Treatment Successful!");
        t->stop();
    }

}

// pause function
// if pauseSingal is false, timer is not pause.
int pauseSingal = false;

void MainWindow :: timePause(QTimer* t){
   if(pauseSingal == false){
       qInfo("Timer paused");
       t->stop();
//     t->setInterval(5000);
       pauseSingal = true;
   }else{
        qInfo("Timer resumed");
        t->start();
        pauseSingal = false;
   }

}

// stop function
void MainWindow :: timeStop(QTimer* t){
   t->stop();
}

// clisk Pause BUtton
void MainWindow::clickPauseButton(){
    timePause(t);
}

// clisk stop BUtton
void MainWindow::clickStopButton(){
    qInfo("Stop Running!");
    timeStop(t);
}



//click new session
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

        QString treatmentStart = "QPushButton {background-color: rgb(143, 240, 164);}";
        ui->Light_Green->setStyleSheet(treatmentStart);

        QString treatmentEnd = "QPushButton {background-color: rgb(38, 162, 105);}";
        ui->Light_Green->setStyleSheet(treatmentEnd);
    }

    mOp->EEGBaseline();

    changeBatteryLevel(mOp->getBattery() - 10.0);

    ui->mainMenuListView->setVisible(false);

    // make a new t
    QTimer *tNew = new QTimer();
    t = tNew;
    initializeTimer(t);

}



// click logs
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
    ui->programViewWidget->setVisible(true);
    ui->List_View->setVisible(false);
    ui->scrollArea->setVisible(true);
}



// code core, control system
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

            break;
        }

    }
}

