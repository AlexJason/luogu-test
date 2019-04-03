#include <iostream>

using namespace std;

int main() {
	int n, m, err, t = 0;
	int err_time[] = { 5, 3, 1, 6, 2 };
	cin >> n >> m;
	while (n--) {
		cin >> err;
		t += err_time[err - 1];
	}
	if (24 - m < t) cout << "BugJump,Loser!" << endl;
	else cout << "BugJump,Yes!" << endl;
	return 0;
}

