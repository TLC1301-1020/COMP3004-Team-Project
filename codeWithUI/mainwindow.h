#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

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

private slots:
    // main menu
    void navigateToMainMenu();
    void playButton();


};
#endif // MAINWINDOW_H
