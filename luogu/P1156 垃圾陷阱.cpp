#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 3050
bool dp[MAX_N][MAX_N][2];
struct input_t {
    int t, f, h;
    bool operator<(const input_t &op) const {
        return t < op.t;
    }
} ipt[MAX_N];

int main() {
    int d, g;
    cin >> d >> g;
    int s = 1;
    int ans1 = 0x3f3f3f3f;
    int ans2 = 0;
    for (int i = 0; i <= 10; ++i) dp[i][0][s ^ 1] = true;
    for (int i = 1; i <= g; ++i) {
        cin >> ipt[i].t >> ipt[i].f >> ipt[i].h;
    }
    sort(ipt + 1, ipt + 1 + g);
    for (int i = 1; i <= g; ++i) {
        const int &t = ipt[i].t, &f = ipt[i].f, &h = ipt[i].h;
        for (int tx = t; tx < MAX_N; ++tx) {
            for (int hx = 0; hx <= d + h; ++hx) {
                dp[tx][hx][s] = false;
                if (tx - f >= t) dp[tx][hx][s] |= dp[tx - f][hx][s ^ 1];
                if (hx - h >= 0) dp[tx][hx][s] |= dp[tx][hx - h][s ^ 1];
                if (dp[tx][hx][s] && hx >= d) {
                    //cout << "D " << tx << " " << hx << " " << s << " " << t << " " << f << " " << h << " "
                    //    << dp[tx - f][hx][s ^ 1] << " " << dp[tx][hx - h][s ^ 1] << endl;
                    ans1 = min(ans1, tx);
                }
                if (dp[tx][hx][s]) {
                    //cout << "E " << tx << " " << hx << " " << s << " " << t << " " << f << " " << h << " "
                    //    << dp[tx - f][hx][s ^ 1] << " " << dp[tx][hx - h][s ^ 1] << endl;
                    ans2 = max(ans2, tx);
                }
            }
        }
        s ^= 1;
    }
    if (ans1 == 0x3f3f3f3f) cout << ans2 << endl;
    else cout << ans1 << endl;
    return 0;
}
