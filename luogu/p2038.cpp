#include <iostream>
#include <algorithm>

using namespace std;

namespace ac {
    int map[130][130];
}

int main() {
    int d, n;
    cin >> d >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, k;
        cin >> x >> y >> k;
        ac::map[x + 1][y + 1] = k;
    }
    int r = 0, c = 0;
    for (int i = 1; i <= 129 + d; ++i) {
        for (int j = 1; j <= 129 + d; ++j) {
            if (i <= 129 && j <= 129) ac::map[i][j] += ac::map[i - 1][j] + ac::map[i][j - 1] - ac::map[i - 1][j - 1];
            if (i > d && j > d) {
                int t = ac::map[min(129, i)][min(129, j)];
                if (i > d * 2 + 1 && j > d * 2 + 1) t = t - ac::map[i - d * 2 - 1][min(129, j)] - ac::map[min(129, i)][j - d * 2 - 1] + ac::map[i - d * 2 - 1][j - d * 2 - 1];
                else if (i > d * 2 + 1) t = t - ac::map[i - d * 2 - 1][min(129, j)];
                else if (j > d * 2 + 1) t = t - ac::map[min(129, i)][j - 2 * d - 1];
                if (r < t) {
                    r = t;
                    c = 1;
                }
                else if (r == t) {
                    ++c;
                }
            }
        }
    }
    cout << c << " " << r << endl;
    return 0;
}
