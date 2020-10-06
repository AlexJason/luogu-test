#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

inline int pos(int m, int n, int i, int j, int k, int l) {
    return i * n * m * n + j * m * n + k * n + l;
}

int main() {
    int m, n;
    cin >> m >> n;
    ++m, ++n;
    int *matrix = new int[m * n];
    int *dp = new int[m * n * m * n];
    memset(dp, 0, sizeof(int) * m * n * m * n);
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            cin >> matrix[i * n + j];

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            for (int k = 1; k < m; ++k) {
                for (int l = 1; l < n; ++l) {
                    dp[pos(m, n, i, j, k, l)] = max(
                        max(dp[pos(m, n, i - 1, j, k - 1, l)], dp[pos(m, n, i - 1, j, k, l - 1)]),
                        max(dp[pos(m, n, i, j - 1, k - 1, l)], dp[pos(m, n, i, j - 1, k, l - 1)])
                    ) + matrix[i * n + j] + ((i != k || j != l) ? matrix[k * n + l] : 0);
                }
            }
        }
    }

    cout << dp[m * n * m * n - 1] << endl;

    return 0;
}
