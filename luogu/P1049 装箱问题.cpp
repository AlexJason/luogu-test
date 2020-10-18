#include <iostream>
#include <algorithm>

using namespace std;

int dp[20010], v[30];

int main() {
    int s, n;
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int t = s; t > 0; --t) {
            if (t >= v[i]) dp[t] = max(dp[t], dp[t - v[i]] + v[i]);
        }
    }
    cout << s - dp[s] << endl;
    return 0;
}