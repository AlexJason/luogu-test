#include <iostream>
#include <algorithm>
using namespace std;
 
#define MAX_N 100005
int c[MAX_N];
// I have submited C code to B QAQ
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> c[i];
        int res = 0x3f3f3f3f;
        for (int co = 1; co <= 100; ++co) {
            int r = 0;
            for (int i = 0; i < n; ++i) {
                if (c[i] != co) i = i + k - 1, ++r;
            }
            res = min(res, r);
        }
        cout << res << endl;
    }
    return 0;
}
