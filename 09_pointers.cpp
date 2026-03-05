// File: 09_pointers.cpp
// C++ Pointers - Basic Example
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    
    // Declare a pointer to an integer
    int* ptr;
    
    // Store the address of variable x in the pointer ptr
    ptr = &x;
    
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value stored in pointer ptr: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    
    return 0;
}