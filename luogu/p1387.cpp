#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n, m, t, r = 0;
    cin >> n >> m;
    int *l = new int[2 * (m + 1)];
    int *lp = l + m + 1;
    l[0] = lp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            cin >> t;
            if (t) l[j] = min(l[j - 1], min(lp[j], lp[j - 1])) + t;
            else l[j] = 0;
            r = max(l[j], r);
        }
        swap(l, lp);
    }
    cout << r << endl;
    return 0;
}

