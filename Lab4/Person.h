#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
using namespace std;

class Person{
    private: 
        string name;
        double salary;

    public:
        void setPerson(string name, double salary);
        string getName();
        double getSalary();
};
#endif //_PERSON_H