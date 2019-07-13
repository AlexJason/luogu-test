#include <iostream>

using namespace std;

int main() {
    int n, l, t, r = 0;
    bool f = false;
    cin >> n >> l;
    while (--n) {
        cin >> t;
        if (l == 1) {
            r += t == 2 ? 3 - f : 4;
        }
        else {
            if (t == 1) {
                r += l == 2 ? 3 : 4;
            }
            else {
                cout << "Infinite" << endl;
                return 0;
            }
        }
        f = l == 3;
        l = t;
    }
    cout << "Finite" << endl << r << endl;
    return 0;
}

