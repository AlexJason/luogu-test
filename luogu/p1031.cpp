#include <iostream>

using namespace std;

int main() {
    int n, s = 0, r = 0, t = 0;
    cin >> n;
    int *m = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        s += m[i];
    }
    s /= n;
    for (int i = 0; i < n; ++i) {
        if (r > 0)
            ++t;
        r += m[i] - s;
        if (r < 0)
            ++t;
    }
    cout << t << endl;
    return 0;
}

