#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 1000005
#define MAX_M 2000005
#define MOD 100003

struct edge_t {
    int v, next;
} edge[MAX_M * 2];
int head[MAX_N];
int cnt[MAX_N];
int cur = 1;

int n, m;

inline void add_edge(int u, int v) {
    edge[cur].v = v;
    edge[cur].next = head[u];
    head[u] = cur++;
}

bool inq[MAX_N];
int tt[MAX_N];
int dis[MAX_N];
void spfa(int s) {
    queue<int> q;
    q.push(s);
    for (int i = 1; i <= n; ++i) dis[i] = 0x3f3f3f3f;
    dis[s] = 0;
    cnt[s] = 1;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        inq[c] = false;
        for (int e = head[c]; e; e = edge[e].next) {
            if (dis[c] + 1 < dis[edge[e].v]) {
                if (!inq[edge[e].v]) {
                    q.push(edge[e].v);
                }
                cnt[edge[e].v] = cnt[c];
                dis[edge[e].v] = dis[c] + 1;
            }
            else if (dis[c] + 1 == dis[edge[e].v]) {
                (cnt[edge[e].v] += cnt[c]) %= MOD;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == y) continue;
        add_edge(x, y);
        add_edge(y, x);
    }
    spfa(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}
