// File: 05_number_pattern.cpp
// Loop - Print Number Pattern
#include <iostream>
using namespace std;

int main() {
    int number = 1;
    int rows = 5;
    
    // Outer loop for rows
    for(int i = 1; i <= rows; i++) {
        // Inner loop for columns
        for(int j = 1; j <= i; j++) {
            cout << number << " ";
            number++;
        }
        // Print new line for each row
        cout << endl;
    }
    
    return 0;
}