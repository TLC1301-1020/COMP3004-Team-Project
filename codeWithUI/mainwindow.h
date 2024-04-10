#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

// Class
#include "Mainoperation.h"

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

    MainOperation* operationMenu;
    MainOperation* operationMenuOG;


    void initializeMainMenu(MainOperation*);
    void updateMenu(const QStringList);
    void navigateUpMenu();
    void navigateDownMenu();

private slots:
    // main menu
    void navigateToMainMenu();


};
#endif // MAINWINDOW_H
