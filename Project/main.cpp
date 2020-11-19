//Raymond Guevara Lozano
//CECS 282 Project - part 2
#include <iostream>
#include <vector>
#include <typeinfo>
#include <typeindex>
#include "Employee.cpp"
#include "Staff.cpp"
#include "Education.cpp"
#include "Faculty.cpp"
#include "Partime.cpp"

std::vector<Employee *> Employee::employees(100); // 100 is max number of employees
int Employee::n{};

void Employee::add(){
    char input;
    std::cout << "'f' to add a Faculty"
                 "\n's' to add a staff"
                 "\n'p' to add a Parttime"
                 "\nEnter selection: ";
    std::cin >> input;
    switch (input)
    { //create specified employee type
    case 'f':
        employees[n] = new Faculty();
        break;
    case 's':
        employees[n] = new Staff();
        break;
    case 'p':
        employees[n] = new Partime();
        break;
    default:
        std::cout << "\nUnknown employee type\n";
        return;
    }
    employees[n++]->getData(); //get employee data from user !!!Implement a getData method
}

int main(){
    std::vector<Employee *> e;

    e.push_back(new Staff("Allen", "Paita", "123", M, "2/23/1959", 50.00));
    e.push_back(new Faculty("Andrade", "Christopher", "623", M, "5/22/1980", AS, Education("MS", "Physical Education", 0)));
    e.push_back(new Partime("Aldaco", "Marque", "945", M, "11/24/1988", 20.00, 35));
    e.push_back(new Staff("Rios", "Enrique", "789", M, "6/2/70", 40.00));
    e.push_back(new Faculty("Johnson", "Anne", "243", F, "4/27/1962", FU, Education("PhD", "Engineering", 3)));
    e.push_back(new Staff("Zapata", "Steven", "456", F, "7/12/1964", 35.00));
    e.push_back(new Partime("Guzman", "Augusto", "455", F, "8/10/1977", 35.00, 30));
    e.push_back(new Faculty("Bouris", "William", "791", F, "3/14/1975", AO, Education("PhD", "English", 1)));
    e.push_back(new Partime("Depirro", "Martin", "678", F, "9/15/1987", 30.00, 15));

    int i {1};0

    double parTimeSalary{0};
    double totalMonSal{0};
    for (Employee* &employee : e){
        std::cout << i << ".";
        employee->putData();
        std::cout << std::endl;
        ++i;
        if (typeid(Partime) == typeid(*employee))
        {
            parTimeSalary += employee->monthlyEarnings();
        }
        totalMonSal += employee->monthlyEarnings();
    }
    std::cout << "Total monthly salary for all part-time staff: $" << parTimeSalary << std::endl;
    std::cout << "Total monthly salary for all employees: $" << totalMonSal << std::endl;
    for (Employee* &employee : e){
        delete employee;
    }

    return 0;
}