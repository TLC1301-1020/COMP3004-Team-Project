#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QVBoxLayout>
#include <QTime>
#include <QGraphicsScene>

// Class
#include "menu.h"
#include "mainoperation.h"
#include "logs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QListWidget *activeQListWidget;

    Menu* operationMenu;
    Menu* operationMenuOG;

    bool menuState;

    MainOperation* mOp;

    QVBoxLayout* logArea;
    QWidget* widget;

    QString timeString;

    int currentTimerCount;
    QTimer *t = new QTimer();

    QGraphicsScene *sceneNewSession;
    QGraphicsScene *sceneTimer;


    bool powerStatu = false;


    void initializeMainMenu(Menu*);
    void updateMenu(const QStringList);
    void navigateUpMenu();
    void navigateDownMenu();
    void newSession();
    void readLogs();

    // timer function
    void initializeTimer(QTimer*);
    void timePause(QTimer* t);
    void timeStop(QTimer* t);

    //time and date
    void timeAndDate();

private slots:
    // main menu
    void navigateToMainMenu();
    void playButton();
    void changeBatteryLevel(double);
    void clickStartButton();
    void clickPauseButton();
    void clickStopButton();
    void updateTimer();

};
#endif // MAINWINDOW_H
