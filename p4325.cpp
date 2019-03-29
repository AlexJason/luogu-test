#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int count[42];
	memset(count, 0, sizeof(int) * 42);
	int input, result = 0;
	for (int i = 0; i < 10; ++i) {
		cin >> input;
		if (++count[input % 42] == 1) ++result;
	}
	cout << result;
	return 0;
}
