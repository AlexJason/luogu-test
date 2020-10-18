#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void bfs(short *m, short n);

int main() {
	short n;
	cin >> n;
	n += 2;
	short *matrix = new short[n * n];
	memset(matrix, 0, sizeof(short) * n);
	for (int i = 1; i < n - 1; ++i) {
		matrix[i * n] = matrix[i * n - 1] = 0;
		for (int j = 1; j < n - 1; ++j) cin >> matrix[i * n + j];
	}
	memset(matrix + n * (n - 1), 0, sizeof(short) * n);
	bfs(matrix, n);
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) cout << 2 - matrix[i * n + j] << ' ';
		cout << endl;
	}
	delete[] matrix;
	return 0;
}

void bfs(short *m, short n) {
	static queue<short> q;
	m[0] = true;
	q.push(0);
	q.push(0);
	while (!q.empty()) {
		short x = q.front();
		q.pop();
		short y = q.front();
		q.pop();
		if (y + 1 < n && !m[x * n + y + 1]) m[x * n + y + 1] = 2, q.push(x), q.push(y + 1);
		if (y - 1 >= 0 && !m[x * n + y - 1]) m[x * n + y - 1] = 2, q.push(x), q.push(y - 1);
		if (x + 1 < n && !m[(x + 1) * n + y]) m[(x + 1) * n + y] = 2, q.push(x + 1), q.push(y);
		if (x - 1 >= 0 && !m[(x - 1) * n + y]) m[(x - 1) * n + y] = 2, q.push(x - 1), q.push(y);
	}
}