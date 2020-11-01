#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct item_t {
    int w, v;
};

inline item_t ctor(int w, int v) {
    item_t x;
    x.w = w;
    x.v = v;
    return x;
}

int dp[1010];
vector<item_t> group[1010];

int main() {
    int n, m, maxc = 0;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        maxc = max(maxc, c);
        group[c].push_back(ctor(a, b));
    }
    for (int i = 1; i <= maxc; ++i) {
        for (int s = m; s > 0; --s) {
            for (int j = 0; j <= group[i].size(); ++j) {
                if (group[i][j].w <= s)
                    dp[s] = max(dp[s], dp[s - group[i][j].w] + group[i][j].v);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}