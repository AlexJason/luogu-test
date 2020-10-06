#include <iostream>

using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m;
    bool *num = new bool[(n + 1) / 2];
    num[0] = false;
    for (int i = 1; i < (n + 1) / 2; ++i) {
        num[i] = true;
    }
    for (int i = 3; i <= n; i += 2) {
        if (num[(i - 1) / 2]) {
            for (int j = 2; i * j <= n; ++j) {
                if ((i * j) & 1) {
                    num[i * j / 2] = false;
                }
            }
        }
    }
    while (m--) {
        cin >> t;
        if (t == 2) cout << "Yes" << endl;
        else if ((t & 1) == 0) cout << "No" << endl;
        else cout << (num[t / 2] ? "Yes" : "No") << endl;
    }
    return 0;
}

