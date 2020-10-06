#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 100005
#define MAX_M 200005

struct edge_t {
    int v, next;
} edge[MAX_M];
int head[MAX_N];
int din[MAX_N];
int dout[MAX_N];
int d[MAX_N];
int cur = 1;

int n, m;

int add_edge(int u, int v) {
    edge[cur].v = v;
    edge[cur].next = head[u];
    head[u] = cur;
    ++dout[u], ++din[v];
    ++cur;
}

int dfs(int u) {
    if (d[u]) return d[u];
    int ans = 0;
    if (dout[u] == 0 && din[u] > 0) ++ans;
    for (int e = head[u]; e; e = edge[e].next) {
        ans += dfs(edge[e].v);
    }
    return d[u] = ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (din[i] == 0) ans += dfs(i);
    }
    cout << ans << endl;
    return 0;
}
