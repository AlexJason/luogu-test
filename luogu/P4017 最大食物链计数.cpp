#include <cstdio>
using namespace std;

#define MAX_M 500005
#define MAX_N 5005
#define MOD 80112002

struct edge_t {
    int v, next;
} edge[MAX_M];
int head[MAX_N];
int c_in[MAX_N];
int t_in[MAX_N];
int c_out[MAX_N];
int cnt[MAX_N];
int cur = 1;

void add_edge(int u, int v) {
    edge[cur].v = v;
    edge[cur].next = head[u];
    head[u] = cur++;
}

void dfs(int s) {
    if (c_out[s] == 0) return;
    for (int e = head[s]; e; e = edge[e].next) {
        (cnt[edge[e].v] += cnt[s]) %= MOD;
        --c_in[edge[e].v];
        if (c_in[edge[e].v] == 0) dfs(edge[e].v);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add_edge(a, b);
        ++c_in[b], ++t_in[b], ++c_out[a];
    }
    for (int i = 1; i <= n; ++i) {
        if (t_in[i] == 0) cnt[i] = 1, dfs(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (c_out[i] == 0) (ans += cnt[i]) %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}
