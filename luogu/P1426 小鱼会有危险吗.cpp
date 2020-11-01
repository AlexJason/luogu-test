#include <iostream>

using namespace std;

int main() {
	int s, x;
	cin >> s >> x;
	double v = 7.0, d = 0.0;
	while (d < s - x) {
		d += v;
		v *= 0.98;
	}
	cout << (d + v <= s + x ? "y" : "n") << endl;
	return 0;
}
