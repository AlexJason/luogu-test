#include <iostream>
#include <limits>
#include <algorithm>

#define xy(x, y) (x) * n + (y)

using namespace std;

inline int add(const int &a, const int &b) {
    if (a == numeric_limits<int>::max() || b == numeric_limits<int>::max()) {
        return numeric_limits<int>::max();
    }
    return a + b;
}

int main() {
    int n;
    cin >> n;
    int *val = new int[n];
    int *dis = new int[n * n];
    for (int i = 0; i < n * n; ++i) {
        dis[i] = numeric_limits<int>::max();
    }
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> val[i] >> l >> r;
        dis[xy(i, i)] = 0;
        if (l) dis[xy(i, l - 1)] = dis[xy(l - 1, i)] = 1;
        if (r) dis[xy(i, r - 1)] = dis[xy(r - 1, i)] = 1;
    }
    
    // Floyd
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                dis[xy(i, j)] = min(dis[xy(i, j)], add(dis[xy(i, k)], dis[xy(k, j)]));
            }
        }
    }

    int r = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        int t = 0;
        for (int j = 0; j < n; ++j) t += dis[xy(i, j)] * val[j];
        r = min(r, t);
    }

    cout << r << endl;

    return 0;
}

