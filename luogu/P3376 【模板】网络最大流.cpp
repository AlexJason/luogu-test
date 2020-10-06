#include <iostream>
#include <queue>

using namespace std;

struct edge_t {
    long long w;
    int to;
    int next;
} edge[10005];
int cur = 2;
int head[205];
//int pre[205];
//long long flow[205];

int depth[205];
int chd[205];
int num[205];

int n, m;

inline void add(int u, int v, int w) {
    edge[cur].w = w;
    edge[cur].to = v;
    edge[cur].next = head[u];
    head[u] = cur;
    ++cur;
}

/*long long ek(int s, int t) {
    queue<int> q;
    for (int i = 0; i < 205; ++i) pre[i] = -1, flow[i] = 1ll << 32;
    q.push(s);
    pre[s] = 0;
    while (!q.empty()) {
        int d = q.front();
        q.pop();
        for (int e = head[d]; e != 0; e = edge[e].next) {
            if (d == t) {
                int k = pre[t];
                const int w = flow[t];
                while (k > 1) {
                    edge[k].w -= w;
                    edge[k ^ 1].w += w;
                    //cout << edge[k^1].to << "(" << k << ") ";
                    k = pre[edge[k ^ 1].to];
                }
                return w;
            }
            const int to = edge[e].to;
            if (edge[e].w > 0 && pre[to] == -1) {
                pre[to] = e;
                //cout << "D " << edge[e].w << " " << flow[d] << " " << to << endl;
                flow[to] = min(edge[e].w, flow[d]);
                q.push(to);
            }
        }
    }
    return -1;
}*/

/*long long dinic_dfs(int s, int t, int d, long long fl) {
    //cout << "D " << d << " " << fl << endl;
    if (d == t || fl == 0) {
        return fl;
    }
    long long ff = fl;
    for (int e = chd[d]; e != 0; e = edge[e].next, chd[d] = e) {
        //cout << "E " << e << " " << edge[e].to << " " << depth[edge[e].to] << endl;
        if (depth[edge[e].to] == depth[d] + 1) {
            int f = dinic_dfs(s, t, edge[e].to, min(fl, edge[e].w));
            if (f == 0) continue;
            edge[e].w -= f;
            edge[e ^ 1].w += f;
            fl -= f;
            if (fl == 0) break;
        }
    }
    //cout << "R " << d << " " << ff - fl << endl;
    return ff - fl;
}

long long dinic(int s, int t) {
    // bfs分层
    queue<int> q;
    q.push(s);
    for (int i = 0; i < 205; ++i) depth[i] = -1, chd[i] = head[i];
    depth[s] = 0;
    while (!q.empty()) {
        int m = q.front();
        q.pop();
        for (int e = head[m]; e != 0; e = edge[e].next) {
            //cout << "BFS " << edge[e].to << " " << edge[e].w << endl;
            if (depth[edge[e].to] == -1 && edge[e].w > 0) {
                depth[edge[e].to] = depth[m] + 1;
                q.push(edge[e].to);
            }
        }
    }
    if (depth[t] == -1) return 0; // 到汇点没有增广路

    return dinic_dfs(s, t, s, 1ll << 32);
}*/

long long isap_dfs(int s, int t, int d, long long fl) {
    //cout << "DFS " << d << " " << fl << endl;
    if (d == t || fl == 0) return fl;
    long long ff = fl;
    for (int e = chd[d]; e != 0; e = edge[e].next, chd[d] = e) {
        //cout << "E " << d << " " << edge[e].to << " " << depth[edge[e].to] << " " << depth[d] << endl;
        if (depth[edge[e].to] == depth[d] - 1) {
            int f = isap_dfs(s, t, edge[e].to, min(fl, edge[e].w));
            if (f == 0) continue;
            edge[e].w -= f;
            edge[e ^ 1].w += f;
            fl -= f;
            if (fl == 0) break;
        }
    }
    int minx = 0x3f3f3f3f;
    for (int e = head[d]; e != 0; e = edge[e].next) {
        if (edge[e].w > 0) minx = min(minx, depth[edge[e].to]);
    }
    int tmp = depth[d];
    --num[tmp];
    if (minx == 0x3f3f3f3f) depth[d] = n;
    else depth[d] = minx + 1;
    //cout << "U " << tmp << " " << depth[d] << endl;
    ++num[depth[d]];
    if (num[tmp] == 0) depth[d] = n;
    return ff - fl;
}

long long isap(int s, int t) {
    queue<int> q;
    q.push(t);
    for (int i = 0; i < 205; ++i) depth[i] = -1;
    depth[t] = 0;
    while (!q.empty()) {
        int d = q.front();
        q.pop();
        if (d == s) continue;
        for (int e = head[d]; e != 0; e = edge[e].next) {
            if (depth[edge[e].to] == -1 && edge[e].w == 0) {
                depth[edge[e].to] = depth[d] + 1;
                ++num[depth[d] + 1];
                q.push(edge[e].to);
            }
            //cout << "BFS " << edge[e].to << " " << depth[edge[e].to] << endl;
        }
    }
    if (depth[s] == -1) return 0;

    long long res = 0, r = 0;
    do {
        res += r;
        //cout << "R " << r << endl;
        for (int i = 0; i < 205; ++i) chd[i] = head[i];
    } while ((r = isap_dfs(s, t, s, 1ll << 32)) != 0);

    return res;
}

int main() {
    int s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    cout << isap(s, t) << endl;
    return 0;
}
