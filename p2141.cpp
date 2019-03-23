#include <iostream>
#include <set>

int main() {
	int n, t, c = 0;
	std::cin >> n;
	std::set<int> s;
	while(n--) {
		std::cin >> t;
		s.insert(s.end(), t);
	}
	for (std::set<int>::iterator i = s.begin(); i != s.end(); ++i) {
		for (std::set<int>::iterator j = s.begin(); j != i; ++j) {
			t = *i - *j;
			if (t != *j && s.find(t) != s.end()) {
				++c;
				break;
			}
		}
	}
	std::cout << c;
	return 0;
}
