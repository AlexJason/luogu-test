#include <iostream>
#include <iomanip>

int main() {
	double kwh;
	std::cin >> kwh;
	std::cout << std::setprecision(1) << std::fixed;
	if (kwh <= 150)
		std::cout << kwh * 0.4463;
	else if (kwh <= 400)
		std::cout << (kwh - 150) * 0.4663 + 150 * 0.4463;
	else
		std::cout << (kwh - 400) * 0.5663 + 250 * 0.4663 + 150 * 0.4463;
	return 0;
}
