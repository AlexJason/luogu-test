#include <iostream>
#include <algorithm>

using namespace std;

int w[110], v[110], dp[1010];

int main() {
    int t, m;
    cin >> t >> m;
    for (int i = 0; i < m; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        for (int s = t; s > 0; --s) {
            if (s >= w[i]) dp[s] = max(dp[s], dp[s - w[i]] + v[i]);
        }
    }
    cout << dp[t] << endl;
    return 0;
}