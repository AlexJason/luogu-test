#include <iostream>
#include <algorithm>

using namespace std;

struct line_t {
    int l, r;
    bool operator<(const line_t &op) const {
        return l < op.l;
    }
};

int main() {
    int l, m;
    cin >> l >> m;
    line_t *ll = new line_t[m];
    for (int i = 0; i < m; ++i) {
        cin >> ll[i].l >> ll[i].r;
    }
    sort(ll, ll + m);
    int r = -1;
    for (int i = 0; i < m; ++i) {
        if (ll[i].r <= r) continue;
        l -= ll[i].r - ll[i].l + 1;
        if (ll[i].l <= r) l += r - ll[i].l + 1;
        r = ll[i].r, r;
    }
    cout << l + 1 << endl;
    return 0;
}
