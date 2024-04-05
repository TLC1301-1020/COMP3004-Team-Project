#ifndef LIGHT_H
#define LIGHT_H

#include <string>
using namespace std;


class Light
{
  public:
    //Constructor/Destructor
    Light();
    ~Light() {};

    // get
    bool getContactLight();
    bool getTreatmentSignalLight ();
    bool getContactLostLight();

    //set
    void setContactLight(bool contactLightStatu);
    void setTreatmentSignalLight(bool treatmentSignalStatu);
    void setContactLostLight(bool contactLostLightStatu);

  private:
    bool contactLight = false;
    bool treatmentSignalLight = false;
    bool contactLostLight = false;
};

#endif
