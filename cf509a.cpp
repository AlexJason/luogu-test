#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int *matrix = new int[n * n];
	for (int i = 0; i < n; ++i) matrix[i] = matrix[i * n] = 1;
	for (int i = 1; i < n; ++i) for (int j = 1; j < n; ++j) matrix[i * n + j] = matrix[(i - 1) * n + j] + matrix[i * n + j - 1];
	cout << matrix[n * n - 1];
	return 0;
}
