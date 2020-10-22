#include <iostream>
#include "Distance.cpp"

int main(){
    Distance d {1,1};
    Distance c {1,1};

    Distance g = d+c;
    Distance f = d-c;

    std::cout << g.getFeet() << " " << g.getInches() << std::endl;
    std::cout << f.getFeet() << " " << f.getInches() << std::endl;
    return 0;
}