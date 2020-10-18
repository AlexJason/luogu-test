#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a0, a1, b0, b1, x, c = 0;
        cin >> a0 >> a1 >> b0 >> b1;
        for (int x = 1; (x * x) <= b1; ++x) {
            if (b1 % x == 0) {
                int k1 = x / a1;
                if (x % a1 == 0 && gcd(k1, a0 / a1) == 1 && gcd(b1 / x, b1 / b0) == 1) ++c;
                if (x * x != b1) {
                    int k2 = b1 / x / a1;
                    if (b1 / x % a1 == 0 && gcd(k2, a0 / a1) == 1 && gcd(x, b1 / b0) == 1) ++c;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}
