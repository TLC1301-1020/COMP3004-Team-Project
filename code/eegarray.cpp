#include <iostream>
#include <iomanip>

#include "eegarray.h"

EEGArray::EEGArray() {
    elements = new EEG*[size];

    for(int i = 0; i < size; i++) {
        elements[i] = new EEG();
    }
}

EEGArray::~EEGArray() {
    for(int i = size-1; i >= 0; i--) {
        delete elements[i];
    }
    delete[] elements;
}
