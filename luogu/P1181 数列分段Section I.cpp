#include <iostream>

using namespace std;

int main() {
    int n, m, c = 0, s = 0, t;
    cin >> n >> m;
    while (n--) {
        cin >> t;
        s += t;
        if (s > m) {
            ++c;
            s = t;
        }
    }
    cout << c + 1 << endl;
    return 0;
}

