#include <iostream>
#include <algorithm>

using namespace std;

struct people_t {
    int w;
    int n;
    bool operator>(const people_t &op) const {
        if (w ^ op.w) return w > op.w;
        return n < op.n;
    }
};

int main() {
    char a = 1;
    int n, k, e[10];
    cin >> n >> k;
    for (int i = 0; i < 10; ++i)
        cin >> e[i];
    people_t *w = new people_t[n];
    for (int i = 0; i < n; ++i) {
        cin >> w[i].w;
        w[i].n = i + 1;
    }
    sort(w, w + n, greater<people_t>());
    for (int i = 0; i < n; ++i) {
        w[i].w += e[i % 10];
    }
    sort(w, w + n, greater<people_t>());
    for (int i = 0; i < k; ++i)
        cout << w[i].n << " ";
    cout << endl;
    return 0;
}