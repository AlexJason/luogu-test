#include <iostream>

using namespace std;

int main() {
    int l, r, t, c = 0;
    cin >> l >> r;
    do {
        t = l;
        while (t) {
            if (t % 10 == 2)
                ++c;
            t /= 10;
        }
    } while (++l <= r);
    cout << c << endl;
    return 0;
}
