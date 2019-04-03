#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	short n, t, c = 0;
	cin >> n;
	short *num = new short[n];
	while (n--) {
		cin >> t;
		for (int i = 0; i < c || (num[c++] = t, 0); ++i) if (num[i] == t) break;
	}
	cout << c << endl;
	sort(num, num + c);
	for (int i = 0; i < c; ++i) cout << num[i] << " ";
	return 0;
}
