#include <iostream>

int main() {
	long long a, b, k;
	std::cin >> a >> b >> k;
	std::cout << a << "^" << b << " mod " << k << "=";
	long long result = 1 % k;
	while (b != 0) {
		if (b & 1)
			(result *= a) %= k;
		(a *= a) %= k;
		b >>= 1;
	}
	std::cout << result << std::endl;
	return 0;
}