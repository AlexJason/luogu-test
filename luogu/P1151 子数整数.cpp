#include <iostream>

using namespace std;

int main() {
	int k;
	bool c = true;
	cin >> k;
	for (int i = 10000; i <= 30000; ++i) {
		if ((i / 100) % k == 0 && (i / 10) % 1000 % k == 0 && i % 1000 % k == 0) {
			cout << i << endl;
			if (c) c = false;
		}
	}
	if (c) cout << "No" << endl;
	return 0;
}
