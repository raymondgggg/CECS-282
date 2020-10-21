#ifndef STAFF_H
#define STAFF_H
#include "Employee.h"
#include <string>


class Staff: public Employee{
    private:
        double hrRate;
    public:
        Staff(std::string lastName, std::string firstName, std::string id, Sex s, std::string bDay, double hrRate);
        Staff();
        double getRate();
        void setRate(double hrRate);
        virtual double monthlyEarnings() override;
        virtual void putData();
        virtual ~Staff();

};

#endif //STAFF_H