#ifndef EEGARRAY_H
#define EEGARRAY_H

#include "eeg.h"

using namespace std;

class EEGArray
{
   public:
    //constructure
    EEGArray();

    //deconstructure
    ~EEGArray();

    // add eeg
    bool add(EEG* eeg);

    //get index = i's element
    EEG* get(int index);

  private:
    EEG** elements;

    //max is 21
    int size = 21;

};

#endif
