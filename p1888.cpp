#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int x, y, z, a, c;
	cin >> x >> y >> z;
	c = max(max(x, y), z);
	a = min(min(x, y), z);
	if (!(a & 1) && !(c & 1)) a >>= 1, c >>= 1;
	vector<int> primers;
	primers.push_back(2);
	bool f;
	const int t = sqrt(a) + 1;
	for (int i = 3; i < t; i += 2) {
		const int t = sqrt(i) + 1;
		f = true;
		for (int j = 0; primers[j] < t; ++j) {
			if (i % primers[j] == 0) {
				f = false;
				break;
			}
		}
		if (f) {
			primers.push_back(i);
			if (!(a % i) && !(c % i)) a /= i, c /= i;
		}
	}
	cout << a << "/" << c;
	return 0;
}
