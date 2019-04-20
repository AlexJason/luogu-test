#include <iostream>
#include <string>

using namespace std;

int main() {
	string isbn;
	cin >> isbn;
	int s = (isbn[0] * 1 + isbn[2] * 2 + isbn[3] * 3 + isbn[4] * 4 + isbn[6] * 5 + isbn[7] * 6 + isbn[8] * 7 + isbn[9] * 8 + isbn[10] * 9 - '0' * 45) % 11;
	if (s == 10) {
		if (isbn[12] == 'X') cout << "Right";
		else isbn[12] = 'X', cout << isbn;
	}
	else {
		if (isbn[12] == s + '0') cout << "Right";
		else isbn[12] = s + '0', cout << isbn;
	}
	return 0;
}
