#include <iostream>
#include <algorithm>

inline int pos(int n, int x = 0, int y = 0, int z = 0, int u = 0) {
	return x + y * n + z * n * n + u * n * n * n;
}

int main() {
	int n, x, y, d;
	std::cin >> n >> x >> y >> d;
	++n;
	int *in = new int[n * n]{ 0 };
	int *map = new int[n * n * n * n]{ 0 };

	while (x || y || d) {
		in[pos(n, x, y)] = d;
		std::cin >> x >> y >> d;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			for (int k = 1; k < n; ++k) {
				for (int l = 1; l < n; ++l) {
					map[pos(n, i, j, k, l)] = std::max(map[pos(n, i - 1, j, k - 1, l)],
						std::max(map[pos(n, i, j - 1, k - 1, l)],
							std::max(map[pos(n, i - 1, j, k, l - 1)],
								map[pos(n, i, j - 1, k, l - 1)]))
					) + in[pos(n, i, j)];
					if (i ^ k || j ^ l) {
						map[pos(n, i, j, k, l)] += in[pos(n, k, l)];
					}
				}
			}
		}
	}

	--n;
	std::cout << map[pos(n + 1, n, n, n, n)];

	return 0;
}
