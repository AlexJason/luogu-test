#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 1005

int x[MAX_N], y[MAX_N], z[MAX_N];

int fa[MAX_N];
void init() {
    for (int i = 0; i < MAX_N; ++i) fa[i] = i;
}
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    fa[find(y)] = find(x);
}

double dist(int i, int j) {
    const double dx = x[i] - x[j], dy = y[i] - y[j], dz = z[i] - z[j];
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, h, r;
        cin >> n >> h >> r;
        init();
        // 0 下表面, 1 上表面
        for (int i = 2; i <= n + 1; ++i) {
            cin >> x[i] >> y[i] >> z[i];
            for (int j = 2; j < i; ++j) {
                if (dist(i, j) <= r * 2) merge(i, j);
            }
            if (z[i] + r >= h) merge(i, 1);
            if (z[i] - r <= 0) merge(i, 0);
        }
        cout << (find(0) == find(1) ? "Yes" : "No") << endl;
    }
    return 0;
}
