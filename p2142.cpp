#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b, c = "";
	cin >> a >> b;
	int last = 0, tmp;

	if (a.size() < b.size()) {
		c = a, a = b, b = c, c = "";
		cout << "-";
	}
	else if (a.size() == b.size()) {
		if (a < b) {
			c = a, a = b, b = c, c = "";
			cout << "-";
		}
	}

	string::reverse_iterator itera = a.rbegin(), iterb = b.rbegin();
	while (itera != a.rend() && iterb != b.rend()) {
		tmp = *itera - *iterb - last;
		if (tmp < 0) last = 1, tmp += 10;
		else last = 0;
		c.insert(c.begin(), tmp + '0');
		++itera, ++iterb;
	}
	while (itera != a.rend()) {
		tmp = *itera - 48 - last;
		if (tmp < 0) last = 1, tmp += 10;
		else last = 0;
		c.insert(c.begin(), tmp + '0');
		++itera;
	}
	
	size_t t = c.find_first_not_of('0');
	if (t == string::npos) cout << "0";
	else cout << c.substr(t);

	return 0;
}