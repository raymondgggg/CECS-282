#include <iostream>
#include "Distance.cpp"

int main(){
    Distance dist1, dist3, dist4; //define distances
    std::cin >> dist1;
    Distance dist2(11, 6.25); //define, initialize dist2
    dist3 = dist1 + dist2;    //single '+' operator
    dist4 = dist1 - dist2;    //friend '-' operators
    //display all lengths
    std::cout << "dist1 = ";
    std::cout << dist1 << std::endl;
    std::cout << "dist2 = ";
    std::cout << dist2 << std::endl;
    std::cout << "dist3 = ";
    std::cout << dist3 << std::endl;
    std::cout << "dist4 = ";
    std::cout << dist4 << std::endl;

    dist2 = dist1++;
    dist3 = dist2 + 10;
    std::cout << "dist2 = ";
    std::cout << dist2 << std::endl;
    std::cout << "dist3 = ";
    std::cout << dist3 << std::endl;
    if(dist4 > dist1){
        std::cout<< "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl;
    }
    return 0;
}