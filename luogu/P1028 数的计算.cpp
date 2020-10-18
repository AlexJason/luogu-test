#include <iostream>

using namespace std;

int calc(int n) {
	static int *m = new int[n / 2 + 1] {0};
	if (n == 1) return 1;
	int result = 1;
	for (int i = n / 2; i > 0; --i) result += m[i] ? m[i] : (m[i] = calc(i));
	return result;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << calc(n);
	return 0;
}
