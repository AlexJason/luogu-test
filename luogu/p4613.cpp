#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int *wand = new int[n];
	int *box = new int[n];
	for (int i = 0; i < n; ++i) cin >> wand[i];
	for (int i = 0; i < n; ++i) cin >> box[i];

	sort(wand, wand + n, greater<int>());
	sort(box, box + n, greater<int>());

	for (int i = 0; i < n; ++i) {
		if (wand[i] > box[i]) {
			cout << "NE" << endl;
			return 0;
		}
	}
	cout << "DA" << endl;

	return 0;
}
