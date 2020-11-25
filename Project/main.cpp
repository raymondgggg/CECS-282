//Raymond Guevara Lozano
//CECS 282 Project - part 2
#include <iostream>
#include <fstream> //for file-stream functions
#include <vector>
#include <typeinfo>
#include <typeindex>
#include "Employee.cpp"
#include "Staff.cpp"
#include "Education.cpp"
#include "Faculty.cpp"
#include "Partime.cpp"
#include <stdlib.h>

std::vector<Employee *> employees(100);
int n {0}; //current number of employees

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
        employees[n] = new Faculty;
        break;
    case 's':
        employees[n] = new Staff;
        break;
    case 'p':
        employees[n] = new Partime;
        break;
    default:
        std::cout << "\nUnknown employee type\n";
        return;
    }
    employees[n++]->getData(); //get employee data from user
}

void Employee::display(){
    for (int j = 0; j < n; j++)
    {
        std::cout << (j + 1);                  //display number
        switch (employees[j]->get_type()) //display type
        {
        case tFaculty:
            std::cout << ". Type: Faculty\n";
            break;
        case tStaff:
            std::cout << ". Type: Staff\n";
            break;
        case tPartime:
            std::cout << ". Type: Part Time\n";
            break;
        default:
            std::cout << ". Unknown type";
        }
        employees[j]->putData(); //display employee data
        std::cout << std::endl;
    }
}

employee_type Employee::get_type(){
    if (typeid(*this) == typeid(Faculty)){
        return tFaculty;
    }
    else if (typeid(*this) == typeid(Staff)){
        return tStaff;
    }
    else if (typeid(*this) == typeid(Partime)){
        return tPartime;
    }
    else{
        std::cerr << "\nBad employee type";
        exit(1);
    }
}
void write() // from example file
{
    int size;
    std::cout << "Writing " << n << " employees.\n";
    std::ofstream ouf;        //open ofstream in binary
    employee_type etype; //type of each employee object

    ouf.open("EMPLOY.DAT", std::ios::trunc | std::ios::binary);
    if (!ouf)
    {
        std::cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < n; j++) //for every employee object
    {                           //get its type
        etype = employees[j]->get_type();
        //write type to file
        ouf.write((char *)&etype, sizeof(etype));
        switch (etype) //find its size
        {
        case tFaculty:
            size = sizeof(Faculty);
            break;
        case tStaff:
            size = sizeof(Staff);
            break;
        case tPartime:
            size = sizeof(Partime);
            break;
        } //write employee object to file
        employees[j]->write(ouf);
        if (!ouf)
        {
            std::cout << "\nCan't write to file\n";
            return;
        }
    }
}

void read()
{
    int size;            //size of employee object
    employee_type etype; //type of employee
    std::ifstream inf;        //open ifstream in binary
    inf.open("EMPLOY.DAT", std::ios::binary);
    if (!inf)
    {
        std::cout << "\nCan't open file\n";
        return;
    }
    n = 0; //no employees in memory yet
    while (true)
    { //read type of next employee
        inf.read((char *)&etype, sizeof(etype));
        if (inf.eof()) //quit loop on eof
            break;
        if (!inf) //error reading type
        {
            std::cout << "\nCan't read type from file\n";
            return;
        }
        switch (etype)
        {              //make new employee
        case tFaculty: //of correct type
            employees[n] = new Faculty;
            size = sizeof(Faculty);
            break;
        case tStaff:
            employees[n] = new Staff;
            size = sizeof(Staff);
            break;
        case tPartime:
            employees[n] = new Partime;
            size = sizeof(Partime);
            break;
        default:
            std::cout << "\nUnknown type in file\n";
            return;
        } //read data from file into it
        employees[n]->read(inf);
        if (!inf) //error but not eof
        {
            std::cout << "\nCan't read data from file\n";
            return;
        }
        n++; //count employee
    }        //end while
    std::cout << "Reading " << n << " employees\n";
}

int main(){
    
    char ch;
    while (true)
    {
        std::cout << "'a' -- add data for an employee"
                "\n'd' -- display data for all employees"
                "\n'w' -- write all employee data to file"
                "\n'r' -- read all employee data from file"
                "\n'x' -- exit"
                "\nEnter selection: ";
        std::cin >> ch;
        switch (ch)
        {
        case 'a': //add an employee to list
            Employee::add();
            break;
        case 'd': //display all employees
            Employee::display();
            break;
        case 'w': //write employees to file
            write();
            break;
        case 'r': //read all employees from file
            read();
            break;
        case 'x':
            std::exit(0); //exit program
        default:
            std::cout << "\nUnknown command";
        }
    }     

    // std::vector<Employee *> e;

    // e.push_back(new Staff("Allen", "Paita", "123", M, "2/23/1959", 50.00));
    // e.push_back(new Faculty("Andrade", "Christopher", "623", M, "5/22/1980", AS, Education("MS", "Physical Education", 0)));
    // e.push_back(new Partime("Aldaco", "Marque", "945", M, "11/24/1988", 20.00, 35));
    // e.push_back(new Staff("Rios", "Enrique", "789", M, "6/2/70", 40.00));
    // e.push_back(new Faculty("Johnson", "Anne", "243", F, "4/27/1962", FU, Education("PhD", "Engineering", 3)));
    // e.push_back(new Staff("Zapata", "Steven", "456", F, "7/12/1964", 35.00));
    // e.push_back(new Partime("Guzman", "Augusto", "455", F, "8/10/1977", 35.00, 30));
    // e.push_back(new Faculty("Bouris", "William", "791", F, "3/14/1975", AO, Education("PhD", "English", 1)));
    // e.push_back(new Partime("Depirro", "Martin", "678", F, "9/15/1987", 30.00, 15));

    // int i {1};

    // double parTimeSalary{0};
    // double totalMonSal{0};
    // for (Employee* &employee : e){
    //     std::cout << i << ".";
    //     employee->putData();
    //     std::cout << std::endl;
    //     ++i;
    //     if (typeid(Partime) == typeid(*employee))
    //     {
    //         parTimeSalary += employee->monthlyEarnings();
    //     }
    //     totalMonSal += employee->monthlyEarnings();
    // }
    // std::cout << "Total monthly salary for all part-time staff: $" << parTimeSalary << std::endl;
    // std::cout << "Total monthly salary for all employees: $" << totalMonSal << std::endl;
    // for (Employee* &employee : e){
    //     delete employee;
    // }

    return 0;
}