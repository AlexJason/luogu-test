#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int v[61], p[61], q[61], s[61];
int dp[32010];
vector<int> fa[61];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> v[i] >> p[i] >> q[i];
        s[i] = v[i] * p[i];
        fa[q[i]].push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        if (q[i]) continue;
        for (int j = n; j > 0; --j) {
            if (j >= v[i]) {
                dp[j] = max(dp[j], dp[j - v[i]] + s[i]);
            }
            if (fa[i].size() > 0 && v[i] + v[fa[i][0]] <= j) {
                const int y = fa[i][0];
                dp[j] = max(dp[j], dp[j - v[i] - v[y]] + s[i] + s[y]);
            }
            if (fa[i].size() > 1) {
                if (v[i] + v[fa[i][1]] <= j) {
                    const int y = fa[i][1];
                    dp[j] = max(dp[j], dp[j - v[i] - v[y]] + s[i] + s[y]);
                }
                if (v[i] + v[fa[i][0]] + v[fa[i][1]] <= j) {
                    const int yv = v[i] + v[fa[i][0]] + v[fa[i][1]];
                    const int ys = s[i] + s[fa[i][0]] + s[fa[i][1]];
                    dp[j] = max(dp[j], dp[j - yv] + ys);
                }
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}