#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> primers;
	primers.push_back(2);
	primers.push_back(3);
	bool f;
	for (int i = 5; i < n - 3; i += 2) {
		int t = sqrt(i) + 1;
		f = true;
		for (int j = 0; primers[j] < t; ++j) {
			if (i % primers[j] == 0) {
				f = false;
				break;
			}
		}
		if (f) primers.push_back(i);
	}
	const int size = primers.size();
	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			if (binary_search(primers.begin(), primers.end(), n - primers[i] - primers[j])) {
				cout << primers[i] << " " << primers[j] << " " << n - primers[i] - primers[j];
				return 0;
			}
		}
	}
	return 0;
}
