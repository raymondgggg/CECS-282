#include <iostream>
#include "Person.cpp"
using namespace std;

void bSort(Person**, int n, bool s);
void order(Person**, Person**);
void test(int x,int y);

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
    for (int i {0}; i < numOfPeople; i++){
        cout << *personPtr + i << "   " << ptr[i] << endl;
    }
    
    return 0;
}

void bSort(Person **person, int n, bool s){
    bool swapped = true;
    int j = 0;
    int tmp;

    while (swapped){
        swapped = false;
        j++;
        for (int i {0}; i < n - j; i++){
            Person personi = *(*(person) + i);
            Person personiPlus1 = *(*(person) + i + 1);
            if (personi.getSalary() > personiPlus1.getSalary()){
                order(person, person);
                swapped = true;
            }
        }
    }
}

void order(Person** personi, Person** personiPlus1){
    Person tmp = **personi;
    **personi = *(*(personiPlus1) + 1);
    **personiPlus1 = tmp;
}

