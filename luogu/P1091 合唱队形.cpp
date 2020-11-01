#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 105
#define INF 0x3f3f3f3f
int d[MAX_N], t[MAX_N];

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) {
        memset(d, 0x3f, sizeof(d));
        for (int j = 1; j <= i - 1; ++j) if (t[j] < t[i])
		    *lower_bound(d + 1, d + n + 1, t[j]) = t[j];
        int k1 = lower_bound(d + 1, d + n + 1, INF) - (d + 1);

        memset(d, 0x3f, sizeof(d));
        for (int j = i + 1; j <= n; ++j) if (t[j] < t[i])
		    *lower_bound(d + 1, d + n + 1, -t[j]) = -t[j];
        int k2 = lower_bound(d + 1, d + n + 1, INF) - (d + 1);

        res = max(res, k1 + k2 + 1);
    }
    cout << n - res << endl;
    return 0;
}
