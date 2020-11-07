#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_N 100005
struct edge_t {
    int v, next;
} edge[MAX_N];
int head[MAX_N];
int cur = 1;
int n, t;

inline void add_edge(int u, int v) {
    edge[cur].v = v;
    edge[cur].next = head[u];
    head[u] = cur++;
}

int dfs(int u) {
    vector<int> vec;
    for (int e = head[u]; e; e = edge[e].next) {
        if (edge[e].v == 0) continue;
        vec.push_back(dfs(edge[e].v));
    }
    sort(vec.begin(), vec.end());
    if (vec.size() == 0) return 1;
    const int req = (vec.size() * t - 1) / 100 + 1;
    int ans = 0;
    for (int i = 0; i < req; ++i) ans += vec[i];
    //cout <<"dfs "<< u << " " << ans << " "<<vec.size()<< endl;
    return ans;
}

int main() {
    while (true) {
        cin >> n >> t;
        if (n == 0 && t == 0) break;
        cur = 1;
        memset(edge, 0, sizeof(edge));
        memset(head, 0, sizeof(head));
        for (int i = 1; i <= n; ++i) {
            int fa;
            cin >> fa;
            add_edge(fa, i);
        }
        cout << dfs(0) << endl;
    }
    return 0;
}
