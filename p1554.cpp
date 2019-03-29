#include <iostream>
#include <cstring>

using namespace std;

int main() {
	long long m, n;
	cin >> m >> n;
	int count[10];
	memset(count, 0, sizeof(int) * 10);
	for (long long i = m; i <= n; ++i) {
		int t = i;
		while (t) {
			++count[t % 10];
			t /= 10;
		}
	}
	for (int i = 0; i < 10; ++i) cout << count[i] << " ";
	return 0;
}
