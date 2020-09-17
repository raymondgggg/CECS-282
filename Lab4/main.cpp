#include <iostream>
#include "Person.cpp"
using namespace std;

void bSort(Person **person, int n, bool s);
void order(Person **personi, Person **personiPlus1);
void display(Person **person, int length);

int main(){
    int numOfPeople {0};
    cout << "How many people would you like to enter? ";
    cin >> numOfPeople; 
    cout << endl;

    Person people[numOfPeople];//declare array of type person 
    Person *ptr[numOfPeople];// have array of pointers of type person 
    
    Person person; //what will be used to add people to array of type person
    double salary {0};
    string name;

    for (int i {0}; i < numOfPeople; i++){//fill up array of type person 
        cout << "Enter the name of person: ";
        cin >> name;
        cout << "Enter the salary of " << name << ": ";
        cin >> salary;
        cout << endl;
        person.setPerson(name,salary);
        people[i] = person;
    }

    for (int i {0}; i < numOfPeople; i++){//fill up array of pointers to objects of type person
        ptr[i] = &people[i];
    }

    Person **personPtr = &ptr[0]; // pointer to the first pointer of type Person in array of pointers

    cout << "People Sorted by Salary: " << endl << endl;
    bSort(personPtr, numOfPeople, false);
    display(personPtr, numOfPeople);
    cout << endl;

    cout << "People Sorted by Name: " << endl << endl;
    bSort(personPtr, numOfPeople, true);
    display(personPtr, numOfPeople);
    cout << endl;
    return 0;
}

void bSort(Person **person, int n, bool s){
    if (!s){ //sorted by salary
        bool swapped = true;
        int j = 0;

        while (swapped)
        {
            swapped = false;
            j++;
            for (int i{0}; i < n - j; i++)
            {
                Person personi = *(*(person) + i);
                Person personiPlus1 = *(*(person) + i + 1);
                if (personi.getSalary() > personiPlus1.getSalary())
                {
                    order(person + i, person + i + 1);
                    swapped = true;
                }
            }
        }
    }
    else{ //sorted by name
        bool swapped = true;
        int j = 0;

        while (swapped)
        {
            swapped = false;
            j++;
            for (int i{0}; i < n - j; i++)
            {
                Person personi = *(*(person) + i);
                Person personiPlus1 = *(*(person) + i + 1);
                if (personi.getName().compare(personiPlus1.getName()) > 0)
                {
                    order(person + i, person + i + 1);
                    swapped = true;
                }
            }
        }
    }
    
}

void order(Person **personi, Person **personiPlus1){
    Person tmp = **personi;
    **personi = *(*(personiPlus1));
    **personiPlus1 = tmp;
}

void display(Person **person, int length){
    for(int i {0}; i < length; i++){
        Person personi = *(*(person) + i);
        printf("%-10s%10.2f", personi.getName().c_str(), personi.getSalary());
        cout << endl;
    }
}