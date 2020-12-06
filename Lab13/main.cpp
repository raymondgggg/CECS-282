#include <iostream>
#include <set>
#include <iterator>
using namespace std;

class person{
    private:
        string lastName;
        string firstName;
        long phoneNumber;
    public:
        person() : lastName("blank"), firstName("blank"), phoneNumber(0L) {

        } 
        person(string lana, string fina, long pho) : lastName(lana), firstName(fina), phoneNumber(pho){

        }
        friend bool operator<(const person&, const person&);
        friend bool operator==(const person&, const person&);
        friend bool operator>(const person&, const person&);

        void display() const{
            cout << endl << lastName << ",\t" << firstName
                << "\t\tPhone: " << phoneNumber;
        }

        long get_phone(){
            return this->phoneNumber;
        }
};

bool operator<(const person& p1, const person& p2){
    if(p1.lastName == p2.lastName)
        return (p1.firstName < p2.firstName) ? true : false;
    return (p1.lastName < p2.lastName) ? true : false;
    
}

bool operator==(const person& p1, const person& p2){
     return (p1.lastName == p2.lastName && p1.firstName == p2.firstName) ? true : false;
}

bool operator>(const person &p1, const person& p2){
    if (p1.lastName == p2.lastName)
        return (p1.firstName > p2.firstName) ? true : false;
    return (p1.lastName > p2.lastName) ? true : false;
    
}

class comparePersons{
    public: 
        bool operator()(const person* ptrP1, const person* ptrP2) const{
            return *ptrP1 < *ptrP2;
        }
};

void searchPerson(string lastName, string firstName, multiset<person *, comparePersons> const &people){
    person searchperson(lastName, firstName, 0);
    person *sPerson = &searchperson;
    int count {0};
    for (person *p : people){
        if(*p == *sPerson)
            count++;
    }

    cout << "Number of matching entries: " << count << endl;
    for (person *p : people){
        if (*p == *sPerson)
            p->display();
    }
    cout << endl;
}
 
int main(){
    multiset<person *, comparePersons> people;

    person *ptrP1 = new person("KuangThu", "Bruce", 4157300);
    person *ptrP2 = new person("Deauville", "William", 8435150);
    person *ptrP3 = new person("Wellington", "John", 9207404);
    person *ptrP4 = new person("Bartoski", "Peter", 6946473);
    person *ptrP5 = new person("Fredericks", "Roger", 7049982);
    person *ptrP6 = new person("McDonald", "Stacey", 7764987);
    person *ptrP7 = new person("KuangThu", "Bruce", 5551230);
    person *ptrP8 = new person("Deauville", "William", 8435150);

    people.insert(ptrP1);
    people.insert(ptrP2);
    people.insert(ptrP3);
    people.insert(ptrP4);
    people.insert(ptrP5);
    people.insert(ptrP6);
    people.insert(ptrP7);
    people.insert(ptrP8);
    
    int usrInput {0};
    cout << "1. Display people\n2. Search Person\n3. Exit program" << endl;
    cin >> usrInput;

    while (usrInput != 3){
        if (usrInput == 1){
            for (person *p : people){
                p->display();
            }
            cout << endl << endl;
        }
        else if (usrInput == 2)
        {
            cin.ignore();
            string lastName;
            string firstName;
            cout << "Enter last name: ";
            getline(cin, lastName);
            cout << "Enter first name: ";
            getline(cin, firstName);
            searchPerson(lastName, firstName, people);
            cout << endl;
        }
        cout << "1. Display people\n2. Search Person\n3. Exit program" << endl;
        cin >> usrInput;
    }
    return 0;
}