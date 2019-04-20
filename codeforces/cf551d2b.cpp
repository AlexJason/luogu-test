#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, h, t;
    cin >> n >> m >> h;
    int *a = new int[m];
    int *b = new int[n];
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t;
            cout << (t ? min(a[j], b[i]) : 0) << " ";
        }
        cout << endl;
    }
    return 0;
}
