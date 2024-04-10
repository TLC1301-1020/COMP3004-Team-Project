#ifndef VIEW_H
#define VIEW_H

#include "menu.h"

class View
{
  public:
    //Constructor/Destructor
    View();
    ~View();

    //open
    void openView();

    //close
    void closeiew();

    //view new session
    void viewNewSession();

    //view session log
    void viewSessionLog();

    //view time and date
    void viewTimeAndDate();

  private:

};

#endif
