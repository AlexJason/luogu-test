#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100005
int a[MAX_N], b[MAX_N];
int n, p;

bool check(double x) {
    double e = x * p;
    for (int i = 0; i < n; ++i) {
        e -= max(0.0, a[i] * x - b[i]);
    }
    return e < 0;
}

int main() {
    cin >> n >> p;
    long long s = 0;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i], s += a[i];
    if (p >= s) {
        cout << -1 << endl;
        return 0;
    }
    double l = 0.0, r = 1e10;
    while (r - l > 1e-5) {
        double m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << l << endl;
    return 0;
}
