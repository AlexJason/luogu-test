#include <iostream>

int main() {
	int n, current, last = 0, day = 0, max = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> current;
		if (last > current) {
			if (day > max) {
				max = day;
			}
			day = 1;
		}
		else {
			++day;
		}
		last = current;
	}
	std::cout << (day > max ? day : max);
	return 0;
}
