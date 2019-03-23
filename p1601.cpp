#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b, c = "";
	cin >> a >> b;
	int last = 0, tmp;
	string::reverse_iterator itera = a.rbegin(), iterb = b.rbegin();
	while (itera != a.rend() && iterb != b.rend()) {
		tmp = *itera + *iterb - 96 + last;
		if (tmp > 9) last = 1, tmp %= 10;
		else last = 0;
		c.insert(c.begin(), tmp + '0');
		++itera, ++iterb;
	}
	if (itera == a.rend()) {
		while (iterb != b.rend()) {
			tmp = *iterb - 48 + last;
			if (tmp > 9) last = 1, tmp %= 10;
			else last = 0;
			c.insert(c.begin(), tmp + '0');
			++iterb;
		}
	}
	else {
		while (itera != a.rend()) {
			tmp = *itera - 48 + last;
			if (tmp > 9) last = 1, tmp %= 10;
			else last = 0;
			c.insert(c.begin(), tmp + '0');
			++itera;
		}
	}
	if (last > 0) {
		cout << last;
	}
	cout << c;
	return 0;
}
