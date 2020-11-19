#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <vector>
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

        static std::vector<Employee *> employees;
        static int n; //current number of employees

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

        static void add(); //part 3 method
        static void display(); //part 3 method
        static void read();//part 3 method
        static void write();//part 3 method

        virtual double monthlyEarnings() = 0;
        virtual ~Employee();
        virtual void getData(); // part 3 method
};
#endif //EMPLOYEE_H