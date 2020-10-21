#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
double FACULTY_MONTHLY_SALARY {5000.00};
double STAFF_MONTHLY_HOURS_WORKED {160};

enum Sex{
    M,F
};

class Employee{
    private:
        std::string lastName;
        std::string firstName;
        std::string id;
        Sex sex;
        std::string bDay;
    public:
        Employee(std::string lastName, std::string firstName, std::string id, Sex sex, std::string bDay);
        Employee();
        virtual void putData();

        std::string getLastName();
        std::string getFirstName();
        std::string getID();
        Sex getSex();
        std::string getbDay();
        void setLastName(std::string lastName);
        void setFirstName(std::string firstName);
        void setID(std::string id);
        void setSex(Sex s);
        void setbDay(std::string bDay);

        virtual double monthlyEarnings() = 0;
        virtual ~Employee();
};
#endif //EMPLOYEE_H