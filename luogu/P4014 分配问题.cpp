#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n; // 1 \le n \le 100

#define MAX_N 205
#define MAX_M 20005

struct edge_t {
    int w, c, to, next;  
} edge[MAX_M];
int head[MAX_N];
int cur = 2;

void add_edge(int u, int v, int w, int c) {
    edge[cur].w = w;
    edge[cur].c = c;
    edge[cur].to = v;
    edge[cur].next = head[u];
    head[u] = cur;
    ++cur;
}

int dis[MAX_N];
bool vis[MAX_N];
int flow[MAX_N];
int pre[MAX_N];
int spfa(int s, int t) {
    queue<int> q;
    q.push(s);
    for (int i = 0; i <= n; ++i) pre[i] = 0, dis[i] = -1;
    dis[s] = 0;
    flow[s] = 1 << 30;
    pre[s] = -1;
    while (!q.empty()) {
        int d = q.front();
        q.pop();
        vis[d] = false;
        for (int e = head[d]; e != 0; e = edge[e].next) {
            if (edge[e].w > 0 && dis[edge[e].to] < dis[d] + edge[e].c) {
                dis[edge[e].to] = dis[d] + edge[e].c;
                if (!vis[edge[e].to]) q.push(edge[e].to);
                flow[edge[e].to] = min(flow[d], edge[e].w);
                pre[edge[e].to] = e;
                if (edge[e].to == t) break;
            }
        }
        cout << "SPFA " << d << " " << dis[d] << endl;
    }
    return dis[t];
}

int cost = 0;
int mcmf(int s, int t) {
    int res = 0;
    while (spfa(s, t) != -1) {
        for (int e = pre[t]; e != -1; e = pre[edge[e ^ 1].to]) {
            cost += flow[t] * edge[e].c;
            edge[e].w -= flow[t];
            edge[e ^ 1].w += flow[t];
        }
        res += flow[t];
        cout << "MCMF " << res << " " << flow[t] << " " << cost << endl;
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        add_edge(1, i + 1, 1, 0);
        add_edge(i + 1, 1, 0, 0);
            cout << "ED " << 1 << " " << i + 1 << endl;
        add_edge(MAX_N - 1, i + n + 1, 1, 0);
        add_edge(i + n + 1, MAX_N - 1, 0, 0);
            cout << "ED " << MAX_N - 1 << " " << i + n + 1 << endl;
        for (int j = 1; j <= n; ++j) {
            int c;
            cin >> c;
            add_edge(i + 1, j + n + 1, 1, c);
            add_edge(j + n + 1, i + 1, 0, -c);
            cout << "ED " << i + 1 << " " << j + n + 1 << endl;
        }
    }
    cout << mcmf(1, MAX_N - 1) << endl << cost << endl;
    return 0;
}

