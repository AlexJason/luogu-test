#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    short a, b;
    cin >> a >> b;
    cout << max(a + b, max(a + a - 1, b + b - 1)) << endl;
    return 0;
}
