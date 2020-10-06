#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int x0, y0;
    cin >> x0 >> y0;
    if (y0 % x0 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int t = y0 / x0;
    int c = 0;
    for (int i = 1; i <= sqrt(t); ++i) {
        if (t % i == 0) {
            if (gcd(t / i, i) == 1) c += (t / i == i ? 1 : 2);
        }
    }
    cout << c << endl;
    return 0;
}
