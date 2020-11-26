#ifndef FACULTY_H
#define FACULTY_H
#include "Employee.h"
#include "Education.h"

enum lvl{
    AS, AO, FU
};

class Faculty: public Employee{
    private:
        lvl l;
        Education ed;

    public:
        Faculty(std::string lastName, std::string firstName, std::string id, Sex s, std::string bDay, lvl l, Education ed);
        Faculty();
        lvl getLvl();
        Education getEd();
        void setLvl(lvl l);
        void setEducation(Education ed);
        virtual double monthlyEarnings() override;
        virtual void putData() override;
        virtual void getData() override; //part 3 method
        virtual void read(std::ifstream& in) override;
        virtual void write(std::ofstream& out) override;
        virtual ~Faculty();
};
#endif //FACULTY_H