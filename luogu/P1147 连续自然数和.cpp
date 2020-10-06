#include <iostream>

using namespace std;

int main() {
	int m;
	cin >> m;
	int beg = 1, end = 0, sum = 1;
	for (end = beg + 1; end <= m / 2 + 1; ++end) {
		sum += end;
		while (sum > m) {
			sum -= beg;
			++beg;
		}
		if (sum == m) {
			cout << beg << " " << end << endl;
		}
	}
	return 0;
}
