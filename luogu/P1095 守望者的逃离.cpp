#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_T 300005
int dp[MAX_T];

int main() {
    int m, s, t;
    cin >> m >> s >> t;
    dp[0] = 0;
    for (int i = 1; i <= t; ++i) {
        if (m >= 10) dp[i] = dp[i - 1] + 60, m -= 10;
        else dp[i] = dp[i - 1], m += 4;
    }
    for (int i = 1; i <= t; ++i) {
        dp[i] = max(dp[i], dp[i - 1] + 17);
        if (dp[i] >= s) {
            cout << "Yes\n" << i << endl;
            return 0;
        }
    }
    cout << "No\n" << dp[t] << endl;
    return 0;
}
