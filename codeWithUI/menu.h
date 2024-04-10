#ifndef MENU_H
#define MENU_H

#include <QString>
#include <QStringList>

#include "headset.h"
#include "logs.h"

class Menu
{
  public:
    //Constructor/Destructor
    Menu(QString, QStringList, Menu*);
    ~Menu();

   // show some information
   //Menu
   QStringList getMenuItems();
   // add child
   void addChildMenu(Menu*);


  // logic operation
  // turn off
  void turnOff();

  // turn on
  void turnOn();

  //new session
  void newSession();

  // session log
  void sessionLog();

  //Time and date
  void timeAndDate();

  private:
  QStringList menuItems;
  QVector<Menu*> subMenus;
  QString name;
  Menu* parent;

};

#endif
