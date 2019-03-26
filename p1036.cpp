#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int calc(int *number, int n, int k, int i, int sum);
bool isPrimer(int x);

int main() {
	int n, k;
	cin >> n >> k;
	int *number = new int[n];
	for (int i = 0; i < n; ++i) cin >> number[i];
	int r = 0;
	for (int i = 0; i <= n - k; ++i)
		r += calc(number, n, k, i, number[i]);
	cout << r;
	return 0;
}

int calc(int *number, int n, int k, int i, int sum) {
	if (k == 1) return isPrimer(sum);
	int c = 0;
	for (int j = i + 1; j <= n - k + 1; ++j) c += calc(number, n, k - 1, j, sum + number[j]);
	return c;
}

bool isPrimer(int x) {
	static vector<int> primers = { 2, 3 };
	static int max_checked = 3;
	if (x == 2) return true;
	if (x & 1) {
		if (x <= max_checked) {
			for (const auto &c : primers) if (c == x) return true;
			return false;
		}
		else {
			while (max_checked < x) {
				max_checked += 2;
				bool flag = true;
				int t = static_cast<int>(sqrt(max_checked)) + 1;
				for (size_t i = 0; primers[i] < t; ++i) {
					if (max_checked % primers[i] == 0) {
						flag = false;
						break;
					}
				}
				if (flag) {
					primers.push_back(max_checked);
				}
			}
			return *primers.rbegin() == x;
		}
	}
	return false;
}
