#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define MAX_N 1005
int dp[MAX_N], t;
bool ch[MAX_N][MAX_N];
string str;

void check() {
    for (int i = 0; i < MAX_N; ++i) for (int j = 0; j < MAX_N; ++j) ch[i][j] = false;
    for (int i = 0; i < str.size(); ++i) {
        for (int l = 0; i - l >= 0 && i + l < str.size(); ++l) {
            if (str[i - l] == str[i + l]) ch[i - l][i + l] = true;
            else break;
        }
        for (int l = 0; i - l >= 0 && i + l + 1 < str.size(); ++l) {
            if (str[i - l] == str[i + l + 1]) ch[i - l][i + l + 1] = true;
            else break;
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> str;
        check();
        dp[0] = 0;
        for (int i = 0; i < str.size(); ++i) {
            dp[i + 1] = dp[i] + 1;
            for (int j = 0; j <= i; ++j) {
                if (ch[j][i]) dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                //cout << "D " << i << " " << j << " " << ch[j][i] << " " << dp[i + 1] << endl;
            }
        }
        cout << dp[str.size()] << endl;
    }
    return 0;
}
