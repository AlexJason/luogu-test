#include <iostream>
#include <vector>

int main() {
	std::vector<unsigned int> vec;
	unsigned int tmp;
	std::cin >> tmp;
	while (tmp) {
		vec.push_back(tmp);
		std::cin >> tmp;
	}
	for (std::vector<unsigned int>::reverse_iterator i = vec.rbegin(); i != vec.rend(); ++i) {
		std::cout << *i << " ";
	}
	return 0;
}
