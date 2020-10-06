#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N 20005
#define MAX_M 100005

int n, m;
struct edge_t {
    int v, w, next;
} edge[MAX_M * 2];
int head[MAX_N];
int color[MAX_N];
int cur = 1;

inline void add_edge(int u, int v, int w) {
    edge[cur].v = v;
    edge[cur].w = w;
    edge[cur].next = head[u];
    head[u] = cur;
    ++cur;
}

int check(int w) {
    for (int i = 1; i <= n; ++i) color[i] = 0;
    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (color[i]) continue;
        q.push(i);
        color[i] = 1;
        while (!q.empty()) {
            int d = q.front();
            q.pop();
            for (int e = head[d]; e; e = edge[e].next) {
                if (edge[e].w > w) {
                    if (color[edge[e].v] == 0) {
                        color[edge[e].v] = -color[d];
                        q.push(edge[e].v);
                    }
                    else if (color[edge[e].v] != -color[d]) {
                        return -1;
                    }
                }
                else {
                    ans = max(ans, edge[e].w);
                }
            }
        }
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    int max_c = 0;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        max_c = max(max_c, c);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    int p = 0, q = max_c, ans = max_c;
    while (p != (p + q) / 2) {
        int t = check((p + q) / 2);
        if (t >= 0) ans = min(t, ans);
        if (t == -1) {
            p = (p + q) / 2;
        }
        else {
            q = (p + q) / 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}
