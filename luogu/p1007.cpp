#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l, n, p;
    cin >> l >> n;
    int nmax = 0, nmin = 0;
    while (n--) {
        cin >> p;
        nmax = max(nmax, max(p, l - p + 1));
        nmin = max(nmin, min(p, l - p + 1));
    }
    cout << nmin << " " << nmax << endl;
    return 0;
}
