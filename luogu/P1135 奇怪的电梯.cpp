#include <iostream>
#include <queue>

using namespace std;

int k[210];
bool vis[210];

int bfs(int n, int a, int b) {
    if (a == b) return 0;
    queue<int> q;
    q.push(a);
    vis[a] = true;
    q.push(0);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        int t = q.front();
        q.pop();
        if (p + k[p] == b || p - k[p] == b) return t + 1;
        if (p + k[p] <= n && !vis[p + k[p]])
            vis[p + k[p]] = true, q.push(p + k[p]), q.push(t + 1);
        if (p - k[p] >= 1 && !vis[p - k[p]])
            vis[p - k[p]] = true, q.push(p - k[p]), q.push(t + 1);
    }
    return -1;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) cin >> k[i];
    cout << bfs(n, a, b) << endl;
    return 0;
}
