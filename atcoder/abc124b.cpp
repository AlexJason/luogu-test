#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    short n, m, h, c = 1;
    cin >> n >> m;
    while (--n) {
        cin >> h;
        if (h >= m) {
            m = h;
            ++c;
        }
    }
    cout << c << endl;
    return 0;
}
