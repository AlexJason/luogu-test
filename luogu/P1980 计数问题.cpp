#include <iostream>

int main() {
	int n, x, c = 0;
	std::cin >> n >> x;
	do {
		for (int t = n; t; t /= 10)
			if (t % 10 == x)
				++c;
	} while (--n);
	std::cout << c;
	return 0;
}
