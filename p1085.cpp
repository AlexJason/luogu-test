#include <iostream>

int main() {
	int a, b, d = 0, m = 7;
	for (int i = 1; i < 8; ++i) {
		std::cin >> a >> b;
		if (a + b > m) {
			d = i;
			m = a + b;
		}
	}
	std::cout << d;
	return 0;
}
