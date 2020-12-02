#include <iostream>
#include <algorithm>
using namespace std;
 
#define MAX_N 100005
int a[MAX_N];
int suf[MAX_N];
 
inline int getr(int x, int y) {
    return suf[y] ^ suf[x - 1];
}
 
int calc(int n) {
    for (int l = 4; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            for (int k1 = i; k1 < j; ++k1) {
                for (int k2 = k1 + 1; k2 < j; ++k2) {
                    if (getr(i, k1) > getr(k1 + 1, k2) || getr(k1 + 1, k2) > getr(k2 + 1, j)) {
                        //cout << "D " << i << " " << k1 << " " << k2 << " " << j << endl;
                        return l - 3;
                    }
                }
            }
        }
    }
    for (int k = 1; k < n; ++k) {
        if (getr(1, k) > getr(k + 1, n)) return n - 2;
    }
    return -1;
}
 
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        suf[i] = suf[i - 1] ^ a[i];
    }
    cout << calc(n) << endl;
    return 0;
}
