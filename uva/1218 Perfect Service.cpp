#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_N 20005
struct edge_t {
    int v, next;
} edge[MAX_N];
int head[MAX_N];
int dp[MAX_N][MAX_N];
int cur = 1;
int n;

inline void add_edge(int u, int v) {
    edge[cur].v = v;
    edge[cur].next = head[u];
    head[u] = cur++;
}

void dfs(int u, int f) {
    int cnt = 0;
    // 0 服务器 儿子可以是服务器也可以是客户端
    // 1 客户端 父亲是服务器 儿子不能是服务器
    // 2 客户端 父亲不是服务器 儿子必须只有一个是服务器
    dp[u][0] = 1;
    dp[u][1] = 0;
    dp[u][2] = MAX_N;
    for (int e = head[u]; e; e = edge[e].next) {
        const int v = edge[e].v;
        if (v == f) continue;
        ++cnt;
        dfs(v, u);
    }
    for (int e = head[u]; e; e = edge[e].next) {
        const int v = edge[e].v;
        if (v == f) continue;
        dp[u][0] += min(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][2];
    }
    for (int e = head[u]; e; e = edge[e].next) {
        const int v = edge[e].v;
        if (v == f) continue;
        dp[u][2] = min(dp[u][2], dp[u][1] - dp[v][2] + dp[v][0]);
    }
    //cout << "D " << u << " " << dp[u][0] << " " << dp[u][1] << " " << dp[u][2] << endl;
}

int main() {
    while (true) {
        if (n == -1) break;
        cin >> n;
        cur = 1;
        memset(edge, 0, sizeof(edge));
        memset(head, 0, sizeof(head));
        for (int i = 2; i <= n; ++i) {
            int a, b;
            cin >> a >> b;
            add_edge(a, b);
            add_edge(b, a);
        }
        dfs(1, 0);
        cout << min(dp[1][0], dp[1][2]) << endl;
        cin >> n;
    }
    return 0;
}
