#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_M 10005
#define MAX_N 105
int dp[MAX_M][MAX_N], v[MAX_N], p[MAX_N];

int main() {
    int n, w;
    cin >> n >> w;
    int minv = 0x3f3f3f3f, sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> p[i];
        minv = min(minv, v[i]);
        sum += v[i];
    }
    --minv;
    sum -= minv * n;
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j > 0; --j) {
            for (int k = n; k > 0; --k) {
                if (j + k * minv <= w && j - (v[i] - minv) >= 0) {
                    dp[j][k] = max(dp[j][k], dp[j - (v[i] - minv)][k - 1] + p[i]);
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            res = max(res, dp[j][i]);
        }
    }
    cout << res << endl;
    return 0;
}
