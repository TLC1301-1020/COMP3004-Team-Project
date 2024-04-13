#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QFile>
#include <QTextStream>

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

    MainOperation* mOp;


    void initializeMainMenu(Menu*);
    void updateMenu(const QStringList);
    void navigateUpMenu();
    void navigateDownMenu();
    void newSession();
    void readLogs();

private slots:
    // main menu
    void navigateToMainMenu();
    void playButton();
    void changeBatteryLevel(double);
    void clickStartButton();


};
#endif // MAINWINDOW_H
