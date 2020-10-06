#include <iostream>

using namespace std;

typedef unsigned long long ull_t;

int main() {
    ull_t n, k;
    cin >> n >> k;
    ull_t m = 1ll << (n - 1);
    while (m > 1) {
        if (k >= m) k = m - (k - m) - 1, cout << '1';
        else cout << '0';
        m >>= 1;
    }
    if (k == 0) cout << '0' << endl;
    else cout << '1' << endl;
    return 0;
}

