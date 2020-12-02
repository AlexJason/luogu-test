#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        cout << max(r - 1, n - r) + max(c - 1, m - c) << endl;
    }
    return 0;
}
