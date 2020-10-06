#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *p = new int[n];
    int *t = new int[n];
    int c = 0, s = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            p[s] = y;
            t[s] = z;
            ++s;
            r += y;
        }
        else {
            int j = c;
            while (j < s && z - t[c] > 45) ++c, ++j;
            while (j < s) {
                if (p[j] >= y) {
                    p[j] = 0;
                    break;
                }
                ++j;
            }
            if (j == s) r += y;
        }
    }
    cout << r << endl;
    return 0;
}

