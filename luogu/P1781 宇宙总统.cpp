// luogu-judger-enable-o2
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m = 0;
	string in;
	string last = "";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> in;
		if (in.size() > last.size() || (in.size() == last.size() && in > last))
			last = in, m = i;
	}
	cout << m + 1 << endl << last << endl;
	return 0;
}
