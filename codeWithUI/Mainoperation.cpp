#include <iostream>
#include <iomanip>

#include "Mainoperation.h"
MainOperation :: MainOperation(QString n, QStringList list, MainOperation* p){
    name = n;
    menuItems = list;
    parent = p;
}

MainOperation :: ~MainOperation() {

    for(int x = 0; x < subMenus.length(); x++) {
        delete subMenus[x];
    }
}

QStringList MainOperation::getMenuItems() { return menuItems; }

void MainOperation::addChildMenu(MainOperation* m) {
    subMenus.push_back(m);
}
