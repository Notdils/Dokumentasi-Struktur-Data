#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<int> myStack;
    
    cout << "=== DEMO STACK SEDERHANA ===" << endl << endl;
    
    // Push beberapa elemen
    int values[] = {10, 20, 30, 40};
    for (int val : values) {
        myStack.push(val);
        cout << val << " berhasil di-push ke stack." << endl << endl;
    }
    
    // Tampilkan isi stack
    cout << "Isi Stack (top → bottom): ";
    stack<int> temp = myStack;  // Copy stack untuk iterasi
    bool first = true;
    while (!temp.empty()) {
        if (!first) cout << " → ";
        cout << temp.top();
        temp.pop();
        first = false;
    }
    cout << endl << endl;
    
    // Tampilkan elemen paling atas
    cout << "Elemen paling atas: " << myStack.top() << endl << endl;
    
    // Tampilkan ukuran stack
    cout << "Ukuran stack: " << myStack.size() << endl << endl;
    
    // Pop beberapa elemen
    cout << myStack.top() << " berhasil di-pop dari stack." << endl;
    myStack.pop();
    
    cout << myStack.top() << " berhasil di-pop dari stack." << endl << endl;
    myStack.pop();
    
    // Tampilkan isi stack setelah pop
    cout << "Isi Stack (top → bottom): ";
    temp = myStack;  // Copy stack lagi
    first = true;
    while (!temp.empty()) {
        if (!first) cout << " → ";
        cout << temp.top();
        temp.pop();
        first = false;
    }
    cout << endl;
    
    // Tampilkan ukuran stack sekarang
    cout << "Ukuran stack sekarang: " << myStack.size() << endl << endl;
    
    return 0;
}
