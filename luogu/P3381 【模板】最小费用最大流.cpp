#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m; // n \le 5000, m \le 50000

#define MAX_N 5005
#define MAX_M 100005

struct edge_t {
    long long w;
    int c, to, next;
} edge [MAX_M];
int head[MAX_N];
//int cur_head[MAX_N];
int pre[MAX_N];
long long flow[MAX_N];
int cur_edge = 2;
int cost = 0;

void add_edge(int u, int v, long long w, int c) {
    edge_t &e = edge[cur_edge];
    e.w = w;
    e.c = c;
    e.to = v;
    e.next = head[u];
    head[u] = cur_edge;
    ++cur_edge;
}

bool in[MAX_N];
int dis[MAX_N];
long long spfa(int s, int t) {
    for (int i = 0; i <= n; ++i) in[i] = false, dis[i] = -1, pre[i] = 0;
    queue<int> q;
    q.push(s);
    in[s] = true;
    dis[s] = 0;
    flow[s] = 1ll << 40;
    pre[s] = -1;
    while (!q.empty()) {
        int d = q.front();
        q.pop();
        in[d] = false;
        for (int e = head[d]; e != 0; e = edge[e].next) {
            if (edge[e].w > 0 && (dis[edge[e].to] == -1 || dis[d] + edge[e].c < dis[edge[e].to])) {
                if (!in[edge[e].to]) q.push(edge[e].to), in[edge[e].to] = true;
                dis[edge[e].to] = dis[d] + edge[e].c;
                flow[edge[e].to] = min(flow[d], edge[e].w);
                pre[edge[e].to] = e;
            }
        }
        //cout << "SPFA " << d << " " << dis[d] << endl;
    }
    return dis[t];
}
/*
long long dinic(int s, int t, int d, long long f) {
    if (d == t || f == 0) return f;
    long long ff = f;
    for (int e = cur_head[d]; e != 0; e = cur_head[d] = edge[e].next) {
        if (dis[edge[e].to] == dis[d] + edge[e].c) {
        //cout << "E " << d << " " << edge[e].to << " " << dis[edge[e].to] << endl;
            long long x = dinic(s, t, edge[e].to, min(f, edge[e].w));
            if (x == 0) continue;
            edge[e].w -= x;
            edge[e ^ 1].w += x;
            cost += x * edge[e].c;
            f -= x;
            //cout << "X " << d << " " << edge[e].to << " " << x << " " << cost << endl;
            if (f == 0) break;
        }
    }
    return ff - f;
}*/

long long ek(int s, int t) {
    /*queue<int> q;
    q.push(s);
    for (int i = 0; i < MAX_N; ++i) pre[i] = 0;
    flow[s] = 1ll << 40;
    pre[s] = -1;
    while (!q.empty()) {
        int d = q.front();
        q.pop();
        for (int e = head[d]; e != 0; e = edge[e].next) {
            if (edge[e].w > 0 && dis[edge[e].to] == dis[d] + edge[e].c) {
            //cout << "E " << d << " " << edge[e].to << " " << edge[e].w << endl;
                if (pre[edge[e].to] == 0) {
                    pre[edge[e].to] = e;
                    flow[edge[e].to] = min(flow[d], edge[e].w);
                    if (d == t) break;
                    q.push(edge[e].to);
                }
            }
        }
    }*/
    for (int e = pre[t]; e != -1; e = pre[edge[e ^ 1].to]) {
        //cout << "B " << edge[e].to << " " << edge[e ^ 1].to << endl;
        cost += edge[e].c * flow[t];
        edge[e].w -= flow[t];
        edge[e ^ 1].w += flow[t];
    }
    return flow[t];
}

int mcmf(int s, int t) {
    int res = 0, r = -1;
    while (spfa(s, t) != -1 && r != 0) {
        //for (int i = 0; i < MAX_N; ++i) cur_head[i] = head[i];
        //res += (r = dinic(s, t, s, 1ll << 40));
        res += (r = ek(s, t));
        //cout << "MCMF " << res << " " << r << " " << cost << endl;
    }
    return res;
}

int main() {
    int s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        int u, v, w, f;
        cin >> u >> v >> w >> f;
        add_edge(u, v, w, f);
        add_edge(v, u, 0, -f);
    }
    cout << mcmf(s, t) << " " << cost << endl;
    return 0;
}
