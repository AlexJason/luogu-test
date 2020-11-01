#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int a, b, c, x, y, z;
	cin >> a >> b >> c;
	bool flag = true;
	bool t[10];
	for (int i = 100; i < 1000; ++i) {
		x = i, y = i * b / a, z = i * c / a;
		if (x >= 100 && x < 1000 && y >= 100 && y < 1000 && z >= 100 && z < 1000) {
			memset(t, 0, sizeof(bool) * 10);
			t[x % 10] = true;
			if (t[(x / 10) % 10]) continue; else t[(x / 10) % 10] = true;
			if (t[x / 100]) continue; else t[x / 100] = true;
			if (t[y % 10]) continue; else t[y % 10] = true;
			if (t[(y / 10) % 10]) continue; else t[(y / 10) % 10] = true;
			if (t[y / 100]) continue; else t[y / 100] = true;
			if (t[z % 10]) continue; else t[z % 10] = true;
			if (t[(z / 10) % 10]) continue; else t[(z / 10) % 10] = true;
			if (t[z / 100]) continue; else t[z / 100] = true;
			if (t[0]) continue;
			cout << x << " " << y << " " << z << endl;
			flag = false;
		}
	}
	if (flag) cout << "No!!!";
	return 0;
}
