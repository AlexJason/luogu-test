#include <iostream>

using namespace std;

int main() {
    char c;
    int t = 0;
    while (cin >> c) if (c == '1') ++t;
    cout << t << endl;
    return 0;
}

