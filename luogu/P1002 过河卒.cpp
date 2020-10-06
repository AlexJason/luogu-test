#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define pos(x, y) ((y) * (n + 1) + (x))

int main() {
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    ++m, ++n;
    long long *map = new long long[(n + 1) * (m + 1)];
    memset(map, 0, (n + 1) * (m + 1) * sizeof(long long));
    map[0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == hy && j == hx)
                continue;
            if (abs(i - hy) == 1 && abs(j - hx) == 2)
                continue;
            if (abs(i - hy) == 2 && abs(j - hx) == 1)
                continue;
            map[pos(j, i + 1)] += map[pos(j, i)];
            map[pos(j + 1, i)] += map[pos(j, i)];
        }
    }
    cout << map[pos(n - 1, m - 1)] << endl;
    return 0;
}

