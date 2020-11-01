#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <utility>

using namespace std;

vector<int> bef, d;

#define push_data(x) \
    if ((ta != a || tb != b) && !s.count(make_pair(ta, tb))) { \
        bef.push_back(t), d.push_back(x); \
        if (tb == n) return d.size() - 1; \
        q.push(ta), q.push(tb), q.push(d.size() - 1); \
        s.insert(make_pair(ta, tb)); \
    }

int bfs(int ca, int cb, int n) {
    queue<int> q;
    set<pair<int, int> > s;
    q.push(0); // a
    q.push(0); // b
    q.push(0); // t
    bef.push_back(-1);
    d.push_back(0);
    s.insert(make_pair<int, int>(0, 0));
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        int b = q.front();
        q.pop();
        int t = q.front();
        q.pop();
        int ta, tb, tc;

        // 1
        ta = ca, tb = b;
        push_data(1);

        // 2
        ta = a, tb = cb;
        push_data(2);

        // 3
        ta = 0, tb = b;
        push_data(3);

        // 4
        ta = a, tb = 0;
        push_data(4);

        // 5
        tc = min(ca - a, b);
        ta = a + tc, tb = b - tc;
        push_data(5);

        // 6
        tc = min(cb - b, a);
        ta = a - tc, tb = b + tc;
        push_data(6);
    }

    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        bef.clear();
        d.clear();
        int ca, cb, n;
        cin >> ca >> cb >> n;
        int t = bfs(ca, cb, n);
        stack<int> s;
        int c = 0;
        while (bef[t] != -1) {
            s.push(d[t]);
            t = bef[t];
            ++c;
        }
        cout << c << " ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    return 0;
}
