#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll_t;

int t[21][21][21];

ll_t ret(ll_t a, ll_t b, ll_t c, ll_t r) {
    if (a >= 0 && b >= 0 && c >= 0 && a <= 20 && b <= 20 && c <= 20) t[a][b][c] = r;
    return r;
}

ll_t w(ll_t a, ll_t b, ll_t c) {
    if (a >= 0 && b >= 0 && c >= 0 && a <= 20 && b <= 20 && c <= 20 && t[a][b][c] != 0) return t[a][b][c];
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if (a < b && b < c) return ret(a, b, c, w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c));
    else return ret(a, b, c, w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a-1, b, c - 1) - w(a - 1, b - 1, c - 1));
}

int main() {
    ll_t a, b, c;
    cin >> a >> b >> c;
    while (a != -1 || b != -1 || c != -1) {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
        cin >> a >> b >> c;
    }
    return 0;
}
