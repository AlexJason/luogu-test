#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100005
int a[MAX_N];
int n, k;

int check(int x) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] / x;
    }
    return ans < k;
}

int main() {
    cin >> n >> k;
    int m = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], m = max(m, a[i]);
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}

