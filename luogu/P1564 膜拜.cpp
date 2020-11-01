#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 2505
int dp[MAX_N], sum1[MAX_N], sum2[MAX_N];
int n, m;

inline bool check(int i, int j) {
    const int s1 = sum1[j] - sum1[i - 1];
    const int s2 = sum2[j] - sum2[i - 1];
    return abs(s1 - s2) <= m || s1 == 0 || s2 == 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t == 1) sum1[i] = 1;
        else sum2[i] = 1;
        sum1[i] += sum1[i - 1];
        sum2[i] += sum2[i - 1];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        if (check(1, i)) dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (check(j + 1, i)) dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
