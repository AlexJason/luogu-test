#include <iostream>
#include <algorithm>

using namespace std;

struct line {
	short n, v;
	bool operator>(const line &b) const {
		return v > b.v;
	}
	bool operator<(const line &b) const {
		return n < b.n;
	}
};

int main() {
	short m, n, k, l, d, x, y, p, q;
	cin >> m >> n >> k >> l >> d;
	--m, --n;
	line *lm = new line[m], *ln = new line[n];
	for (int i = 0; i < m; ++i) lm[i].n = i + 1, lm[i].v = 0;
	for (int i = 0; i < n; ++i) ln[i].n = i + 1, ln[i].v = 0;
	while (d--) {
		cin >> x >> y >> p >> q;
		if (x == p) ++ln[min(y, q) - 1].v;
		else ++lm[min(x, p) - 1].v;
	}
	sort(lm, lm + m, greater<line>());
	sort(lm, lm + k);
	sort(ln, ln + n, greater<line>());
	sort(ln, ln + l);
	for (int i = 0; i < k; ++i) cout << lm[i].n << " ";
	cout << endl;
	for (int i = 0; i < l; ++i) cout << ln[i].n << " ";
	return 0;
}
