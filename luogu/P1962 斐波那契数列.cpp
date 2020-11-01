#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull_t;

//ull_t p = 99261817;
//#define N 3
ull_t p = 1000000007;
#define N 2

void mul(ull_t a[N][N], ull_t b[N][N]) {
    ull_t t[N][N];
    memset(t, 0, sizeof(t));
    for (ull_t i = 0; i < N; ++i) {
        for (ull_t j = 0; j < N; ++j) {
            for (ull_t k = 0; k < N; ++k) {
                t[i][j] += (a[i][k] * b[k][j]) % p;
                t[i][j] %= p;
            }
        }
    }
    for (ull_t i = 0; i < N; ++i) {
        for (ull_t j = 0; j < N; ++j) {
            a[i][j] = t[i][j];
        }
    }
}

/*ull_t res[N][N] = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
};

ull_t t[N][N] = {
    1, 1, 1,
    1, 0, 0,
    0, 1, 0
};*/

ull_t res[N][N] = {
    1, 0,
    0, 1
};

ull_t t[N][N] = {
    1, 1,
    1, 0
};

void qpow(ull_t n) {
    while (n) {
        if (n & 1) mul(res, t);
        mul (t, t);
        n >>= 1;
    }
}

int main() {
    ull_t n;
    cin >> n;
    if (n <= N) cout << 1 << endl;
    else {
        qpow(n - N);
        cout << (res[0][0] + res[0][1])  % p << endl;
        //cout << (res[0][0] + res[0][1] + res[0][2])  % p << endl;
    }
    return 0;
}