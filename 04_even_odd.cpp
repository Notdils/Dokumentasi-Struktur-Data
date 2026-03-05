// File: 04_even_odd.cpp
// Check if a Number is Even or Odd in C++
#include <iostream>
using namespace std;

int main() {
    int n = 11;
    
    // If n is completely divisible by 2
    if(n % 2 == 0)
        cout << "Even";
    // If n is NOT completely divisible by 2
    else
        cout << "Odd";
    
    return 0;
}