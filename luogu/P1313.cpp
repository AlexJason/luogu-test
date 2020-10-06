#include <iostream>
#include <algorithm>

using namespace std;

int qpow(int a, int b, int p) {
    a %= p;
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= p;
        (a *= a) %= p;
        b >>= 1;
    }
    return res;
}

int f[1010];

int c(int n, int m) {
    if (m == 0 || n == m) return 1;
    for (int i = 1; i <= n; ++i) {
        f[0] = 1;
        for (int j = m; j >= 0; --j) {
            f[j] = (f[j] + f[j - 1]) % 10007;
        }
    }
    return f[m];
}

int main() {
    int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    cout << (((c(k, n) * qpow(a, n, 10007)) % 10007) * qpow(b, m, 10007)) % 10007 << endl;
    return 0;
}
