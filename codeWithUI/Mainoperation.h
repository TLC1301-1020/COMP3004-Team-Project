#ifndef MAINOPERATE_H
#define MAINOPERATE_H

#include <QString>
#include <QStringList>

#include "headset.h"
#include "logs.h"

class MainOperation
{
  public:
    //Constructor/Destructor
    MainOperation(QString, QStringList, MainOperation*);
    ~MainOperation();

   // show some information
   //Menu
   QStringList getMenuItems();
   // add child
   void addChildMenu(MainOperation*);


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
  QVector<MainOperation*> subMenus;
  QString name;
  MainOperation* parent;

};

#endif
