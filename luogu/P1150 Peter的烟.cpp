#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int r = n, t = 0;
	while (n >= k) {
		t = n % k;
		n /= k;
		r += n;
		n += t;
	}
	cout << r;
	return 0;
}
