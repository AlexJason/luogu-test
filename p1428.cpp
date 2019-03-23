#include <iostream>

int main() {
	short n, *l;
	std::cin >> n;
	l = new short[n];
	for (short i = 0; i < n; ++i) {
		std::cin >> l[i];
		int c = 0;
		for (short j = 0; j < i; ++j) {
			if (l[j] < l[i]) {
				++c;
			}
		}
		std::cout << c << " ";
	}
	return 0;
}
