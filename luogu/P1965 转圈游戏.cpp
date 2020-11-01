#include <iostream>

using namespace std;

long long qpow(long long a, long long b, long long p) {
    long long res = 1;
    while (b) {
        if (b & 1) (res *= a) %= p;
        (a *= a) %= p;
        b >>= 1;
    }
    return res;
}

int main() {
    long long n, m, k, x;
    cin >> n >> m >> k >> x;
    cout << (qpow(10, k, n) * m + x - 1) % n + 1 << endl;
    return 0;
}
