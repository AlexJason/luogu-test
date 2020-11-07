#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 1005
struct light_t {
    int v, k, c, l;
    bool operator<(const light_t &op) const {
        return v < op.v;
    }
} x[MAX_N];
int dp[MAX_N], sum[MAX_N];

int main() {
    int n;
    cin >> n;
    while (n) {
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            cin >> x[i].v >> x[i].k >> x[i].c >> x[i].l;
        sum[0] = dp[0] = 0;
        sort(x + 1, x + 1 + n);
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + x[i].l;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + x[i].c * x[i].l + x[i].k;
            for (int j = 0; j < i; ++j) {
                dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j]) * x[i].c + x[i].k);
            }
        }
        cout << dp[n] << endl;
        cin >> n;
    }
    return 0;
}
