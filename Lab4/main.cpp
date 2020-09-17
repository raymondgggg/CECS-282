#include <iostream>
#include "Person.cpp"
using namespace std;

void bSort(Person**, int n, bool s);
void order(Person**, Person**);
void test(int x,int y);

int main(){
    int numPeople {};
    



   
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

