#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 105
#define MAX_A 25005

int a[MAX_N], d[MAX_A];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, max_a = 0;
        cin >> n;
        for (int i = 0; i < MAX_A; ++i) d[i] = 0;
        for (int i = 0; i < n; ++i) cin >> a[i], d[a[i]] = 1, max_a = max(max_a, a[i]);
        int cnt = 0;
        for (int i = 0; i <= max_a; ++i) {
            if (d[i] == 0) continue;
            for (int j = 0; j < n; ++j) {
                if (i + a[j] >= MAX_A) continue;
                if (d[i + a[j]] == 1) ++cnt;
                d[i + a[j]] = 2;
            }
        }
        cout << n - cnt << endl;
    }
    return 0;
}

