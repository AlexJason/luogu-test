#include <iostream>

using namespace std;

const int num_cnt[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int cnt(int x);

int main() {
	int n, sum = 0;
	cin >> n;
	n -= 4;
	for (int a = 0; a < 1111; ++a) {
		if ((cnt(a) << 1) + cnt(a << 1) == n) {
			++sum;
		}
		for (int b = a + 1; b < 1111; ++b) {
			if (cnt(a) + cnt(b) + cnt(a + b) == n) {
				sum += 2;
			}
		}
	}
	cout << sum;
	return 0;
}

int cnt(int x) {
	int result = num_cnt[x % 10];
	if (x >= 10) result += cnt(x / 10);
	return result;
}
