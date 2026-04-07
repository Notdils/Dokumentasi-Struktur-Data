#include <bits/stdc++.h>
using namespace std;

int main() {
    
    stack<int> myStack;
    
    cout << "=== DEMO STACK SEDERHANA ===" << endl << endl;
    
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    

    cout << "Elemen paling atas: " << myStack.top() << endl << endl;
    
    cout << "Ukuran stack: " << myStack.size() << endl << endl;
    
    cout << myStack.top() << " berhasil di-pop dari stack." << endl;
    myStack.pop();
    cout << myStack.top() << " berhasil di-pop dari stack." << endl << endl;
    myStack.pop();
    
    // Tampilkan ukuran stack sekarang
    cout << "Ukuran stack sekarang: " << myStack.size() << endl << endl;
    
    return 0;
}
