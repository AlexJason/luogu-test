#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, k, t;
	cin >> n >> k;
	set<int> s;
	while (n--) {
		cin >> t;
		s.insert(t);
	}
	if (s.size() >= k) {
		for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter, --k) {
			if (k == 1) {
				cout << *iter;
				return 0;
			}
		}
	}
	cout << "NO RESULT";
	return 0;
}
