#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

int main(){
    double arr[] = {1.1, 2.2, 3.3, 2.2, 4.4};

    //Determine the array size
    int size {sizeof(arr) / sizeof(arr[1])};
    
    // initialize vector v1 to array arr
    vector<double> vec(size);
    for (int i {0}; i < size; i++){
        vec[i] = arr[i];
    }
    //Display the contents of vector v1
    cout << "Vector Contents: ";
    for (double d : vec){
        cout << d << " ";
    }
    cout << endl;
    // Sorting the Vector in Ascending order
    sort(vec.begin(), vec.end());
    //Display the content of vector v1 after sorting
    cout << "Vector Contents (After sorting): ";
    for (double d : vec)
    {
        cout << d << " ";
    }
    cout << endl; 
    // Reversing the Vector v1
    reverse(vec.begin(), vec.end());
    //Display the content of vector v1
    cout << "Vector Contents (After reversed): ";
    for (double d : vec)
    {
        cout << d << " ";
    }
    cout << endl;
    //Display the maximum element of vector v1
    cout << "Max element: " << *max_element(vec.begin(), vec.end()) << endl;
    //Display the minimum element of vector v1
    cout << "Min element: " << *min_element(vec.begin(), vec.end()) << endl;
    //Display the accumulation of all elements in vector v1
    cout << "Accumulation: " << accumulate(vec.begin(), vec.end(), 0) << endl;
    // Starting the summation from 0

    // Counts the occurrences of 2.2 from 1st to last element
    //Display the counts
    cout << "2.2 Occurences: " << count(vec.begin(), vec.end(), 2.2) << endl;
    // Delete second element of vector
    vec.erase(vec.begin() + 1);
    //Display the v1 after erasing the element
    cout << "Vector Contents (After deleted 2nd element): ";
    for (double d : vec)
    {
        cout << d << " ";
    }
    cout << endl;
    //Remove the duplicate occurrences
    vector<double>::iterator i;
    
    i = unique(vec.begin(), vec.end());
    vec.resize(distance(vec.begin(), i));

    cout << "Vector Contents (After removing duplicates): ";
    for (double d : vec)
    {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}