#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    for (int i = 0; i < 4; ++i) {
        cin >> c;
        b = max(b, c);
    }
    cout << b - a + 1 << endl;
    return 0;
}
