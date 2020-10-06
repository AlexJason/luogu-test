#include <iostream>

int main() {
	int money = 0, save = 0, cost;
	for (int i = 1; i <= 12; ++i) {
		std::cin >> cost;
		money = money + 300 - cost;
		if (money < 0) {
			std::cout << -i;
			return 0;
		}
		save += money - money % 100;
		money %= 100;
	}
	std::cout << money + save * 1.2;
	return 0;
}
