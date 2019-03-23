#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
	unsigned int n, a, b, cost = -1;
	std::cin >> n;
	for (int i = 0; i < 3; ++i) {
		std::cin >> a >> b;
		cost = std::min(cost, static_cast<unsigned int>(std::ceil(static_cast<double>(n) / a) * b));
	}
	std::cout << cost;
	return 0;
}
