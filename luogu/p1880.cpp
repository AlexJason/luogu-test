#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int *s = new int[n * 2 + 1] + 1;
	int *dp_max = new int[n * n * 2];
	int *dp_min = dp_max + n * n;
	//for (int i = 0; i < n * n; ++i) dp_max[i] = dp_min[i] = -1;
	s[-1] = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		s[i] = t + s[i - 1];
		s[i + n] = t;
		dp_max[i * n + i] = dp_min[i * n + i] = 0;
	}
	for (int i = n; i < n * 2; ++i) s[i] += s[i - 1];
	for (int l = 1; l < n; ++l) {
		for (int b = 0; b < n; ++b) {
			int e = (b + l) % n;
			dp_max[b * n + e] = dp_max[(b + 1) % n * n + e] + (s[b + l] - s[b - 1]);
			dp_min[b * n + e] = dp_min[(b + 1) % n * n + e] + (s[b + l] - s[b - 1]);
			for (int k = b + 1; k < b + l; ++k) {
				dp_max[b * n + e] = max(dp_max[b * n + e], dp_max[b * n + k % n] + dp_max[(k + 1) % n * n + e] + (s[b + l] - s[b - 1]));
				dp_min[b * n + e] = min(dp_min[b * n + e], dp_min[b * n + k % n] + dp_min[(k + 1) % n * n + e] + (s[b + l] - s[b - 1]));
			}
		}
	}
	int res_max = dp_max[0 * n + n - 1], res_min = dp_min[0 * n + n - 1];
	for (int i = 1; i < n; ++i) {
		res_max = max(res_max, dp_max[i * n + i - 1]);
		res_min = min(res_min, dp_min[i * n + i - 1]);
	}
	cout << res_min << '\n' << res_max << endl;
	return 0;
}
