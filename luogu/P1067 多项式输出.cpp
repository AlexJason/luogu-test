#include <iostream>

using namespace std;

int main() {
	int n, x;
	cin >> n;
	bool f = true;
	while (n) {
		cin >> x;
		if (x < 0) {
			cout << "-";
			x *= -1;
		}
		else if (x == 0) {
			--n;
			continue;
		}
		else if (!f) {
			cout << "+";
		}
		if (f)
			f = false;
		if (x != 1)
			cout << x;
		if (n == 1)
			cout << "x";
		else
			cout << "x^" << n;
		--n;
	}
	cin >> x;
	if (x > 0)
		cout << "+";
	if (x != 0)
		cout << x;
	return 0;
}

