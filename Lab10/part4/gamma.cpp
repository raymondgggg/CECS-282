#include "gamma.h"

gamma::gamma(){
    this->runningTotal++;
    this->id = runningTotal;
}

gamma::~gamma(){
    cout << "Destroying ID number " << this->id << endl;
}

void gamma::showtotal(){
    cout << "Total is " << runningTotal << endl;
}

void gamma::showid(){
    cout << "ID numer is " << this->id << endl;
}

