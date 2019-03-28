#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned char byte_t;

int eightqueen(int n, byte_t *l, int x, int y);

int main() {
	int n;
	cin >> n;
	byte_t *l = new byte_t[n];
	int result = 0;
	for (int i = 0; i < n; ++i) {
		l[0] = i;
		result += eightqueen(n, l, i, 1);
	}
	cout << result;
	delete l;
	return 0;
}

int eightqueen(int n, byte_t *l, int x, int y) {
	static int count_printed = 0;
	if (y == n) {
		if (count_printed++ < 3) {
			for (int i = 0; i < n; ++i) cout << l[i] + 1 << " ";
			cout << endl;
		}
		return 1;
	}
	int result = 0;
	bool *t = new bool[n];
	memset(t, 0, sizeof(bool) * n);
	for (int i = 0; i < y; ++i) {
		t[l[i]] = true;
		if (l[i] + (y - i) < n) t[l[i] + (y - i)] = true;
		if (l[i] - (y - i) >= 0) t[l[i] - (y - i)] = true;
	}
	for (int j = 0; j < n; ++j) {
		if (!t[j]) {
			l[y] = j;
			result += eightqueen(n, l, x, y + 1);
		}
	}
	delete t;
	return result;
}
