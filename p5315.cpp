#include <iostream>

using namespace std;

int main() {
    int n, l, g, w, h;
    cin >> n >> l >> g;
    while (n--) {
        cin >> w >> h;
        while (w > g || h > g) {
            w >>= 1;
            h >>= 1;
        }
        if (w < l || h < l) {
            cout << "Too Young" << endl;
        }
        else if (w != h) {
            cout << "Too Simple" << endl;
        }
        else {
            cout << "Sometimes Naive" << endl;
        }
    }
    return 0;
}
