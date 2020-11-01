#include <iostream>

using namespace std;

const int SIZE = 5001;
int fa[SIZE];

void init() {
    for (int i = 0; i < SIZE; ++i) fa[i] = i;
}

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

bool comp(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    init();
    while (m--) {
        int i, j;
        cin >> i >> j;
        merge(i, j);
    }
    while (p--) {
        int i, j;
        cin >> i >> j;
        cout << (comp(i, j) ? "Yes" : "No") << endl;
    }
    return 0;
}
