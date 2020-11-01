#include <iostream>
#include <cstring>

using namespace std;

int dfs(bool *map, int m, int n, int sx, int sy, int fx, int fy);

int main() {
	int n, m, t, sx, sy, fx, fy, tx, ty;
	cin >> n >> m >> t >> sx >> sy >> fx >> fy;
	bool *map = new bool[m * n];
	memset(map, 0, sizeof(bool) * m * n);
	for (int i = 0; i < t; ++i) cin >> tx >> ty, map[(ty - 1) * m + tx - 1] = true;
	map[(sy - 1) * m + sx - 1] = true;
	cout << dfs(map, m, n, sx - 1, sy - 1, fx - 1, fy - 1);
	return 0;
}

int dfs(bool *map, int m, int n, int sx, int sy, int fx, int fy) {
	if (sx == fx && sy == fy) return 1;
	int r = 0;
	if (sx + 1 < m && !map[sy * m + sx + 1]) map[sy * m + sx + 1] = true, r += dfs(map, m, n, sx + 1, sy, fx, fy), map[sy * m + sx + 1] = false;
	if (sx - 1 >= 0 && !map[sy * m + sx - 1]) map[sy * m + sx - 1] = true, r += dfs(map, m, n, sx - 1, sy, fx, fy), map[sy * m + sx - 1] = false;
	if (sy + 1 < n && !map[(sy + 1) * m + sx]) map[(sy + 1) * m + sx] = true, r += dfs(map, m, n, sx, sy + 1, fx, fy), map[(sy + 1) * m + sx] = false;
	if (sy - 1 >= 0 && !map[(sy - 1) * m + sx]) map[(sy - 1) * m + sx] = true, r += dfs(map, m, n, sx, sy - 1, fx, fy), map[(sy - 1) * m + sx] = false;
	return r;
}