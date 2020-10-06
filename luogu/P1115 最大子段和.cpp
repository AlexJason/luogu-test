#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a, r, t;
    cin >> n >> r;
    t = r;
    for (int i = 1; i < n; ++i) {
        cin >> a;
        t = max(t + a, a);
        r = max(t, r);
    }
    cout << r << endl;
    return 0;
}
