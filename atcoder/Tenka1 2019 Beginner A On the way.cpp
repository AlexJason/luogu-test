#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    if (a > b) {
        c = a;
        a = b;
        b = c;
    }
    cin >> c;
    if (a <= c && c <= b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;    
}

