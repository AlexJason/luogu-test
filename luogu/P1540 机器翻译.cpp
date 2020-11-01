#include <iostream>

using namespace std;

void check(short *l, short &top, short &count, short m, short t);

int main() {
	short m, n, t;
	cin >> m >> n;
	short *l = new short[m];
	for (int i = 0; i < m; ++i) l[i] = -1;
	short top = -1, count = 0;;
	while (n--) {
		cin >> t;
		check(l, top, count, m, t);
	}
	cout << count;
	return 0;
}

void check(short *l, short &top, short &count, short m, short t) {
	for (int i = 0; i < m; ++i) {
		if (l[i] == -1) {
			if (top == m - 1) top = -1;
			l[++top] = t;
			++count;
			return;
		}
		if (l[i] == t) {
			return;
		}
	}
	if (top == m - 1) top = -1;
	l[++top] = t;
	++count;
}

