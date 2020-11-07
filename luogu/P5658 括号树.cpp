#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

#define MAX_N 500005
long long f[MAX_N], fa[MAX_N], lst[MAX_N], cnt[MAX_N];
char v[MAX_N];

int main() {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; ++i) cin >> v[i];
    for (long long i = 2; i <= n; ++i) cin >> fa[i];
    fa[0] = fa[1] = f[0] = lst[0] = 0;
    long long res = 0;
    for (long long i = 1; i <= n; ++i) {
        if (v[i] == '(') {
            lst[i] = i;
            if (v[fa[i]] == '(') cnt[i] = 0;
            else cnt[i] = cnt[fa[i]];
            f[i] = f[fa[i]];
        }
        else {
            if (lst[fa[i]] != 0) {
                cnt[i] = cnt[lst[fa[i]]] + 1;
                lst[i] = lst[fa[lst[fa[i]]]];
                f[i] = f[fa[i]] + cnt[i];
            }
            else {
                lst[i] = lst[fa[i]];
                cnt[i] = 0;
                f[i] = f[fa[i]];
            }
        }
        //cout << i << ": " << f[i] << " " << cnt[i] << " " << lst[i] << endl;
        res ^= i * f[i];
    }
    cout << res << endl;
    return 0;
}
