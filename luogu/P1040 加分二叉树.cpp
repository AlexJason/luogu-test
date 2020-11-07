#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 35
int d[MAX_N], dp[MAX_N][MAX_N], root[MAX_N][MAX_N];

void print(int x, int y) {
    if (x > y) return;
    int r = root[x][y];
    cout << r << " ";
    print(x, r - 1);
    print(r + 1, y);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < MAX_N; ++i) for (int j = 0; j < MAX_N; ++j) dp[i][j] = 1;
    for (int i = 1; i <= n; ++i) cin >> d[i], dp[i][i] = d[i], root[i][i] = i;
    for (int l = 1; l < n; ++l) {
        for (int i = 1; i <= n; ++i) {
            const int j = i + l;
            if (j > n) break;
            for (int k = i; k <= j; ++k) {
                if (dp[i][k - 1] * dp[k + 1][j] + d[k] > dp[i][j]) {
                    dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + d[k];
                    root[i][j] = k;
                }
            }
        }
    }
    cout<< dp[1][n] <<endl;
    print(1, n);
    return 0;
}
