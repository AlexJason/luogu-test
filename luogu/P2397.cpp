// 涉及内容: 摩尔投票算法(Boyer-Moore Mojority Vote Algorithm)

#include <iostream>

using namespace std;

int main() {
    int n, t, ans = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t != ans) {
            if (cnt > 0) --cnt;
            else if (cnt == 0) ans = t;
            else ans = 0;
        }
        else {
            ++cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
