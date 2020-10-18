#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int *f = new int[n];
	for (int i = 0; i < n; ++i) cin >> f[i];
	while (m--) next_permutation(f, f + n);
	for (int i = 0; i < n; ++i) cout << f[i] << " ";
	cout << endl;
	return 0;
}
