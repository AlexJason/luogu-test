#include <iostream>

using namespace std;

long long frac(long long x) {
    long long r = 1;
    for (long long i = 2; i <= x; ++i) r *= i;
    return r;
}

long long c(long long n, long long m) {
    return frac(n) / (frac(m) * frac(n - m));
}

int main() {
    long long n;
    cin >> n;
    cout << c(2 * n - 2, (2 * n) / 2 - 1) << endl;
    return 0;
}
