#include <iostream>
#include <algorithm>

using namespace std;

struct Apple {
	int height;
	int require;
	bool operator<(const Apple &b) const { return require < b.require; }
};

int main() {
	int n, s, a, b;
	cin >> n >> s >> a >> b;
	b += a;
	Apple *apples = new Apple[n];
	for (int i = 0; i < n; ++i) {
		cin >> apples[i].height >> apples[i].require;
		if (apples[i].height > b) apples[i].require = -1;
	}
	sort(apples, apples + n, less<Apple>());
	int i = 0, c = 0;
	while (apples[i].require == -1) ++i;
	while (i < n) {
		s -= apples[i].require;
		if (s >= 0) ++c;
		else break;
		++i;
	}
	cout << c;
	return 0;
}
