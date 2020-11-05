#include "pointerDataClass.h"

pointerDataClass::pointerDataClass(int size): maxSize {size}, length{size}, p{new int[size]}{
}

pointerDataClass::~pointerDataClass(){
    delete [] this->p;
    this->p = nullptr;
}

void pointerDataClass::insertAt(int index, int num){
    this->p[index] = num;
}

void pointerDataClass::displayData(){
    for (int i {0}; i < this->length; i++){
        cout << this->p[i] << " ";
    }
    cout << endl;
}

pointerDataClass::pointerDataClass(const pointerDataClass &oldObj){
    this->maxSize = oldObj.maxSize;
    this->length = oldObj.length;
    this->p = new int[maxSize]; // allocate new space for the deep copy of the object
    for (int i {0}; i < this->length; i++)
        this->p[i] = oldObj.p[i]; // put the data of the old object into the new object
}