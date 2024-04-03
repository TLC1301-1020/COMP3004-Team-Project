#include <iostream>
#include <iomanip>

#include "eegarray.h"

EEGArray::EEGArray() {

    for(int i = 0; i < size; i++) {
        elements.push_back(new EEG());
    }
}

EEGArray::~EEGArray() {
    for(int i = size-1; i >= 0; i--) {
        delete elements[i];
    }
}

EEG* EEGArray::get(int index) {
    return elements[index];
}
