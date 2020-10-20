#ifndef PUBLICATION_PUBLICATION_H
#define PUBLICATION_PUBLICATION_H
#include <iostream>
#include <string>
using namespace std;

class Publication{
    public:
        //Declare two functions getData and putData
        void getData();
        void putData();

        //Declare title and price
    private:
        string title;
        float price;
};

#endif //PUBLICATION_PUBLICATION_H