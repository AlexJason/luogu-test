#include <iostream>
#include <string>

using namespace std;

string calc(int v);

int main() {
	int n;
	cin >> n;
	const string t = calc(n);
	cout << t.substr(1, t.size() - 2);
	return 0;
}

string calc(int v) {
	if (v == 0) return "(0)";
	else if (v == 1) return "";
	string result = "";
	int i = 0;
	while (v) {
		if (v & 1) {
			result = "2" + calc(i) + "+" + result;
		}
		v >>= 1;
		++i;
	}
	result.erase(--result.end());
	return "(" + result + ")";
}
