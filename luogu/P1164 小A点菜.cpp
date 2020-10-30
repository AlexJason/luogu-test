#include <iostream>
using namespace std;

#define MAX_M 10005
int dp[MAX_M];

int main() {
    int n, m, a;
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        for (int s = m; s >= 0; --s)
            if (s - a >= 0 && (dp[s - a] > 0 || s - a == 0))
                dp[s] += dp[s - a];
    }
    cout << dp[m] << endl;
    return 0;
}
