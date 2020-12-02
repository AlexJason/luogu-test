#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
 
#define MAX_N 1000010
int xx[1005], x[1005];
 
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) cin >> x[i], xx[i] = x[i];
    sort(xx, xx + t);
    map<int, int> res;
    int cur = 0;
    while (xx[cur] == 1) {
        res[1] = 1;
        ++cur;
    }
    for (int l = 3, n = 2; cur < t; n += l++) {
        while (xx[cur] < n + l && cur < t) {
            if (xx[cur] == n + 1) res[n + 1] = l - 1;
            else res[xx[cur]] = l;
            ++cur;
        }
    }
    for (int i = 0; i < t; ++i) {
        cout << res[x[i]] << endl;
    }
    return 0;
}
