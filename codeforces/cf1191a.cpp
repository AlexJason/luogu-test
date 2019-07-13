#include <iostream>

using namespace std;

const int s[4] = { 1, 0, 1, 2 };
const char c[4] = { 'D', 'A', 'C', 'B' };

int main () {
    int x;
    cin >> x;
    cout << s[x & 3] << " " << c[(x + s[x & 3]) & 3] << endl;
    return 0;
}
