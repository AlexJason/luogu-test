#include <iostream>

using namespace std;

void exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    else {
        exgcd(b, a % b, x, y);
        int t = y;
        y = x - a / b * y, x = t;
    }
}

int main() {
    int a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << (x % b + b) % b << endl;
    return 0;
}