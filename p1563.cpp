#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int *d = new int[n];
	string *p = new string[n];
	for (int i = 0; i < n; ++i)
		cin >> d[i] >> p[i];
	int a, s;
	int c = 0;
	while (m--) {
		cin >> a >> s;
		if (a)
			if (d[c])
				c -= s;
			else
				c += s;
		else
			if (d[c])
				c += s;
			else
				c -= s;
		if (c >= n)
			c -= n;
		if (c < 0)
			c += n;
	}
	cout << p[c] << endl;
	return 0;
}

