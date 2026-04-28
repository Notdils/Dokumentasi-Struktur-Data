#include <bits/stdc++.h>

using namespace std;


int utama(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

void FungsiPostfix(string s) {
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isalnum(c)) { res += c; } 
        else if (c == '(') { st.push('('); } 
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop(); 
        } 
        else {
            while (!st.empty() && utama(s[i]) <= utama(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << "Ekspresi Postfix: " << res << endl;
}

int main() {
    string ekspresi = "a+(2*b^3)/(f-g)+d*h";
    FungsiPostfix(ekspresi);
    return 0;
}
