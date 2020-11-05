#include "alpha.h"

void alpha::display(){
    cout << this->data << endl;
}

alpha::alpha():data {0}{
}

alpha::alpha(int data): data {data}{
}