#include <iostream>
#include <algorithm>

using namespace std;

struct item_t {
    int h, id;
};

int s = 0;
item_t a[100010];
int c[100010];

void reset() {
    for (int i = 0; i < 100010; ++i) {
        c[i] = 0;
    }
}

void add(int x, int p) {
    const int t = p;
    while (x <= s) {
        c[x] = max(c[x], t);
        x += x & (-x);
    }
}

int get(int x) {
    int res = 0;
    while (x > 0) {
        res = max(res, c[x]);
        x -= x & (-x);
    }
    return res;
}

bool comp1(const item_t &a, const item_t &b) {
    if (a.h == b.h) return a.id < b.id;
    return a.h > b.h;
}

bool comp2(const item_t &a, const item_t &b) {
    if (a.h == b.h) return a.id > b.id;
    return a.h < b.h;
}

int main() {
    int x, i = 1;
    while (cin >> x) {
        a[i].h = x;
        a[i].id = i;
        ++i;
        ++s;
    }
    sort(a + 1, a + s + 1, comp1);
    for (int i = 1; i <= s; ++i) {
        add(a[i].id, get(a[i].id) + 1);
    }
    int res1 = get(s);
    reset();
    sort(a + 1, a + s + 1, comp2);
    for (int i = 1; i <= s; ++i) {
        add(a[i].id, get(a[i].id) + 1);
    }
    int res2 = get(s);
    cout << res1 << endl << res2 << endl;
    return 0;
}