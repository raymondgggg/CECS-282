#ifndef PARTIME_H
#define PARTIME_H
#include "Staff.h"
#include <string>

class Partime: public Staff{
    private:
        double hrWk;
    public: 
        Partime(std::string lastName, std::string firstName, std::string id, Sex s, std::string bDay, double hrRate, double hrWk);
        Partime();
        double getHrWk();
        void setHrWk(double hr);
        virtual double monthlyEarnings() override;
        virtual void putData() override;
        virtual void getData() override;
        virtual ~Partime();
};
#endif //PARTIME_H