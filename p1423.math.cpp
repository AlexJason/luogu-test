#include <iostream>
#include <cmath>

int main() {
	double x;
	std::cin >> x;
	std::cout << static_cast<int>(std::ceil(std::log(1-x/100)/std::log(1.98)));
	return 0;
}
