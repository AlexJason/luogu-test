#include <iostream>
#include <algorithm>

int main() {
	long n;
	int x;
	std::cin >> x >> n;
	long d = n + x - 1;
	std::cout << d / 7 * 1250 + std::min(d % 7, 5l) * 250 - std::min(x - 1, 5) * 250;
	return 0;
}
