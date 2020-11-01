#include <iostream>
#include <algorithm>

using namespace std;

int m[110][110];
int d[110][110];

int dfs(int r, int c, int x, int y) {
    if (d[x][y] > 0) return d[x][y];
    int t = 0;
    if (x > 0 && m[x][y] > m[x - 1][y]) t = max(t, dfs(r, c, x - 1, y));
    if (x < r - 1 && m[x][y] > m[x + 1][y]) t = max(t, dfs(r, c, x + 1, y));
    if (y > 0 && m[x][y] > m[x][y - 1]) t = max(t, dfs(r, c, x, y - 1));
    if (y < c - 1 && m[x][y] > m[x][y + 1]) t = max(t, dfs(r, c, x, y + 1));
    return d[x][y] = t + 1;
}

int main() {
    int r, c, res = 1;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
        cin >> m[i][j];
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
        res = max(res, dfs(r, c, i, j));
    cout << res << endl;
    return 0;
}
