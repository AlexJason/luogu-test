#include <iostream>

using namespace std;

int main() {
	int n, last, tmp, cnt = 1, max = 1;
	cin >> n >> last;
	while (--n) {
		cin >> tmp;
		if (tmp - 1 == last) ++cnt;
		else max = cnt > max ? cnt : max, cnt = 1;
		last = tmp;
	}
	cout << (cnt > max ? cnt : max);
	return 0;
}
