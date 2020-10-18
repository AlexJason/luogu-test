#include <iostream>
using namespace std;

class Rug {
private:
	int x;
	int y;
	int w;
	int h;
public:
	friend istream &operator>>(istream &i, Rug &r) {
		return i >> r.x >> r.y >> r.w >> r.h;
	}
	bool contains(int x0, int y0) {
		return x0 >= x && x0 <= x + w && y0 >= y && y0 <= y + h;
	}
};

int main() {
	int n, x, y;
	Rug *map;
	cin >> n;
	map = new Rug[n];
	for (int i = 0; i < n; i++)
		cin >> map[i];
	cin >> x >> y;
	
	for (int i = n - 1; i >= 0; i--)
		if (map[i].contains(x, y))
			return cout << i + 1, 0;
	cout << -1;
	return 0;
}