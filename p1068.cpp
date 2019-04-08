#include <iostream>
#include <algorithm>

using namespace std;

struct people {
    short k;
    short s;
    bool operator>(const people &op) const {
        return s ^ op.s ? s > op.s : k < op.k;
    }
};

int main() {
    short n, m;
    cin >> n >> m;
    people *p = new people[n];
    for (int i = 0; i < n; ++i)
        cin >> p[i].k >> p[i].s;
    sort(p, p + n, greater<people>());
    m = m * 3 / 2;
    cout << p[m - 1].s << ' ';
    while (p[m].s == p[m - 1].s)
        ++m;
    cout << m << endl;
    for (int i = 0; i < m; ++i)
        cout << p[i].k << ' ' << p[i].s << endl;
    return 0;
}
