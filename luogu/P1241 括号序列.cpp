#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define MAX_L 105
bool ispair[MAX_L];

int main() {
    string a;
    cin >> a;
    stack<char> s;
    stack<int> t;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == ')') {
            if (!s.empty() && s.top() == '(') {
                ispair[t.top()] = ispair[i] = true;
                s.pop(), t.pop();
            }
        }
        else if (a[i] == ']') {
            if (!s.empty() && s.top() == '[') {
                ispair[t.top()] = ispair[i] = true;
                s.pop(), t.pop();
            }
        }
        else {
            s.push(a[i]);
            t.push(i);
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        if (ispair[i]) {
            cout << a[i];
        }
        else {
            if (a[i] == '[' || a[i] == ']') cout << "[]";
            else if (a[i] == '(' || a[i] == ')') cout << "()";
        }
    }
    cout << endl;
    return 0;
}
