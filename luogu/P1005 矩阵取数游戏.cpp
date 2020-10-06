#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

void print(__int128 v);

int main() {
	int n, m;
	cin >> n >> m;
	int *line = new int[m];
	__int128 *d = new __int128[m * m];
	__int128 *base = new __int128[m];

	base[0] = 2;
	for (int i = 1; i < m; ++i) base[i] = base[i - 1] << 1;

	__int128 score = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> line[j];
		for (int j = 0; j < m; ++j) d[j * m + j] = line[j] * base[m - 1];

		for (int j = m - 2; j >= 0; --j) {
			for (int k = j + 1; k < m; ++k) {
				d[j * m + k] = max(line[j] * base[m - (k - j) - 1] + d[(j + 1) * m + k],
					line[k] * base[m - (k - j) - 1] + d[j * m + k - 1]);
			}
		}
		score += d[m - 1];
	}
	print(score);
	return 0;
}

void print(__int128 v) {
	if (v > 10) print(v / 10);
	putchar(v % 10 + '0');
}
