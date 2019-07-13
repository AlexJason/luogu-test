#include <iostream>
#include <algorithm>

using namespace std;

struct point {
    int l, r;
    bool operator<(const point &op) const {
        return r < op.r;
    }
};

int main() {
    int n;
    cin >> n;
    point *p = new point[n];
    for (int i = 0; i < n; ++i)
        cin >> p[i].l >> p[i].r;
    sort(p, p + n);
    int r = -1, c = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].l >= r) {
            ++c;
            r = p[i].r;
        }
    }
    cout << c << endl;
    return 0;
}
