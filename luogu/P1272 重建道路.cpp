#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_N 300
struct edge_t {
    int v, next;
} edge[MAX_N];
int head[MAX_N];
int cur = 1;
int n, p;
int dp[MAX_N][MAX_N], cnt[MAX_N];
int deg[MAX_N];

inline void add_edge(int u, int v) {
    edge[cur].v = v;
    edge[cur].next = head[u];
    head[u] = cur++;
    ++deg[u];
}

void dfs(int u, int f) {
    cnt[u] = 1;
    dp[u][1] = 0;
    for (int e = head[u]; e; e = edge[e].next) {
        const int v = edge[e].v;
        if (v == f) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        // 01背包
        for (int s = cnt[u]; s >= 1; --s) {
            dp[u][s] = dp[u][s] + 1; //前x-1个节点滚过来的, 不选需要多删一条边
            for (int k = 0; k < s; ++k) {
                dp[u][s] = min(dp[u][s], dp[u][s - k] + dp[v][k]);
            //cout << "D " << u << " " << s << " " << v << " " << k << " = " << dp[u][s]<< endl;
            }
        }
    }
}

int main() {
    cin >> n >> p;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        add_edge(b, a);
    }
    memset(dp, 0x3f, sizeof(dp));
    dfs(1, 0);
    int ans = dp[1][p];
    for (int i = 2; i <= n; ++i) ans = min(ans, dp[i][p] + 1);
    cout << ans << endl;
    return 0;
}
