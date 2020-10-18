#include <iostream>
#include <cmath>

using namespace std;

// Disjoint Set
const int SIZE = 30001;
int fa[SIZE], si[SIZE], dis[SIZE];

void ds_init() {
    for (int i = 0; i < SIZE; ++i) fa[i] = i, si[i] = 1, dis[i] = 0;
}

int ds_find(int x) {
    if (fa[x] == x) return x;
    int tmp = ds_find(fa[x]);
    dis[x] += dis[fa[x]];
    return fa[x] = tmp;
}

void ds_merge(int x, int y) {
    int fax = ds_find(x), fay = ds_find(y);
    fa[fax] = fay;
    dis[fax] += si[fay];
    si[fay] = si[fax] + si[fay];
}

int main() {
    int t;
    cin >> t;
    ds_init();
    while (t--) {
        char x;
        int i, j;
        cin >> x >> i >> j;
        if (x == 'M') {
            ds_merge(i, j);
        }
        else {
            if (ds_find(i) == ds_find(j)) {
                cout << abs(dis[j] - dis[i]) - 1 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}