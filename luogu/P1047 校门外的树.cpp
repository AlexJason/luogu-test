#include <iostream>

int main() {
	int l, m, a, b, c = 0;
	std::cin >> l >> m;
	bool* r = new bool[l + 1];
	for (int i = 0; i < l + 1; ++i) {
		r[i] = true;
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> a >> b;
		for (int j = a; j <= b; ++j) {
			if (r[j]) {
				r[j] = false;
				++c;
			}
		}
	}
	std::cout << l - c + 1;
	return 0;
}
