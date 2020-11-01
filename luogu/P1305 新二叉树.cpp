#include <iostream>
#include <cstdio>

using namespace std;

void dlr(int *left, int *right, int root) {
	putchar(root + 'a');
	if (left[root] != -1) dlr(left, right, left[root]);
	if (right[root] != -1) dlr(left, right, right[root]);
}

int main() {
	int n;
	char d, l, r;
	cin >> n;
	int left[26], right[26];
	for (int i = 0; i < 26; ++i) left[i] = right[i] = -1;
	while (getchar() != '\n');
	char root = getchar();
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		if (flag) d = root, flag = false;
		else d = getchar();
		l = getchar(), r = getchar();
		while (getchar() != '\n');
		left[d - 'a'] = l ^ '*' ? l - 'a' : -1;
		right[d - 'a'] = r ^ '*' ? r - 'a' : -1;
	}
	dlr(left, right, root - 'a');
	return 0;
}
