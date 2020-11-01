#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10005
#define MAX_M 1005
#define INF 0x3f3f3f3f
struct pipe_t {
    int p, l, h;
    bool operator<(const pipe_t &x) const {
        return p < x.p;
    }
} pipe[MAX_N];
int x[MAX_N], y[MAX_N];
int dp[MAX_N][MAX_M];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> pipe[i].p >> pipe[i].l >> pipe[i].h;
    }
    for (int i = 1; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_M; ++j) dp[i][j] = INF;
    }
    sort(pipe, pipe + k);
    int cur = 0;
    int f = true;
    for (int i = 1; i <= n; ++i) {
        int l = 1, h = m;
        if (k != 0 && pipe[cur].p == i) l = pipe[cur].l + 1, h = pipe[cur].h - 1, ++cur;
        for (int j = x[i - 1]; j < m; ++j) {
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j - x[i - 1]], dp[i][j - x[i - 1]]) + 1);
        }
        for (int j = m - x[i - 1]; j <= m; ++j) {
            dp[i][m] = min(dp[i][m], min(dp[i - 1][j], dp[i][j]) + 1);
        }
        for (int j = 1; j <= m - y[i - 1]; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j + y[i - 1]]);
        }
        int mx = INF;
        for (int j = 0; j <= m; ++j) {
            if (j < l || j > h) dp[i][j] = INF;
            else mx = min(mx, dp[i][j]);
        }
        if (mx == INF) {
            if (k != 0 && pipe[cur - 1].p == i) --cur;
            f = false;
            break;
        }
    }
    if (f) {
        int res = INF;
        for (int i = 1; i <= m; ++i) res = min(res, dp[n][i]);
        cout << 1 << endl << res << endl;
    }
    else {
        cout << 0 << endl << cur << endl;
    }
    return 0;
}
