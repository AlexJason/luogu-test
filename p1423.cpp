#include <iostream>

int main() {
	double x, m = 2, p = 2;
	int step = 1;
	std::cin >> x;
	while (m < x)
		step++, p *= 0.98, m += p;
	std::cout << step;
	return 0;
}
