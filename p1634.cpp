#include <iostream>

using namespace std;

inline long long pow(int a, int b);

int main() {
	int x, n;
	cin >> x >> n;
	cout << pow(x + 1, n);
	return 0;
}

inline long long pow(int a, int b) {
	long long ans = 1, base = a;
	while (b) {
		if (b & 1) ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}
