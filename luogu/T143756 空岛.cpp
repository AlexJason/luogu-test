#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 1000005
#define MAX_M 1500005

struct edge_t {
    int v, next;
} edge[MAX_M];
int head[MAX_N];
int d[MAX_N];
int da[MAX_N];
int cur = 1;

int n, m, s;

int add_edge(int u, int v) {
    edge[cur].v = v;
    edge[cur].next = head[u];
    head[u] = cur;
    ++cur;
}

int dfs(int u) {
    if (d[u]) return d[u];
    int ans = 0;
    for (int e = head[u]; e; e = edge[e].next) {
        ans = max(ans, dfs(edge[e].v));
    }
    return d[u] = ans + da[u];
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &da[i]);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add_edge(a, b);
    }
    printf("%d\n", dfs(s));
    return 0;
}
