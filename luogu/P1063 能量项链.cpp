#include <iostream>
using namespace std;

#define MAX_N 105
int a[MAX_N];
int dp[MAX_N][MAX_N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n; ++i) {
            const int j = i + l - 1;
            const int j2 = j <= n ? j : j - n;
            dp[i][j2] = 0;
            for (int k = i; k < j; ++k) {
                const int k2 = k <= n ? k : k - n;
                dp[i][j2] = max(dp[i][j2], dp[i][k2] + dp[(k % n) + 1][j2] + a[i] * a[(k % n) + 1] * a[(j % n) + 1]);
            }
        }
    }
    int ans = dp[1][n];
    for (int i = 2; i <= n; ++i) {
        ans = max(ans, dp[i][i - 1]);
        //cout << i << " " << dp[i][i - 1] << endl;
    }
    cout << ans << endl;
    return 0;
}
