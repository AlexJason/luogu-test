#include <iostream>

int main() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	a = a * 60 + b;
	c = c * 60 + d;
	a = c - a;
	std::cout << a / 60 << " " << a % 60;
	return 0;
}
